//
// Created by ilyas on 04.11.2021.
//

#include "../file_word_searcher.h"
#include <pthread.h>
#include <zconf.h>

typedef struct pthread_args {
  char* data;
  size_t data_size;
  size_t word_len;
} pthread_args_t;

static void Pthread_args_init(pthread_args_t* args) {
  args->data = NULL;
  args->data_size = 0;
  args->word_len = 0;
}

static size_t search_closest_next_space(const char* data) {
  size_t i = 0;
  for (; data[i] != ' ' && data[i] != EOF; i++);
  return i;
}

static size_t* count_data_parts(const char* data, size_t data_length,
                         size_t processors_count) {
  size_t* data_parts = malloc(sizeof(size_t) * processors_count);
  if (data_parts == NULL) {
    return NULL;
  }

  size_t data_part_size = data_length / processors_count - 1;
  data_parts[0] = data_part_size +
                  search_closest_next_space(&data[data_part_size]);
  for (size_t i = 1; i < processors_count - 1; i++) {
    if (data_length - data_parts[i - 1] > data_part_size) {
      data_parts[i] = data_part_size + data_parts[i - 1] +
                      search_closest_next_space(&data[data_part_size
                                                      + data_parts[i-1]]);
    }
    else {
      data_parts[i] = data_parts[i-1];
    }
  }
  data_parts[processors_count - 1] = data_length - 1;

  return data_parts;
}

static char* pthread_search_long_word(pthread_args_t* args) {
  char* longest_word = search_long_word(args->data, args->data_size,
                                        &args->word_len);
  return longest_word;
}

char* file_long_word_search(const char* filename, size_t* word_length) {
  size_t data_length = 0;
  char* data = read_file_to_mem(filename, &data_length);
  if (data == NULL) {
    return NULL;
  }

  size_t processors_count = sysconf(_SC_NPROCESSORS_ONLN);

  size_t* data_parts = count_data_parts(data, data_length, processors_count);
  if (data_parts == NULL) {
    free(data);
    return NULL;
  }

  size_t pthread_count = 1;
  for(size_t i = 1; i < processors_count; i++) {
    if (data_parts[i] > data_parts[i - 1]) {
      pthread_count++;
    }
  }

  pthread_t* threads = malloc(sizeof(pthread_t) * pthread_count);

  pthread_args_t* threads_args = malloc(sizeof(pthread_args_t) * pthread_count);
  for (size_t i = 0; i < pthread_count; i++) {
    Pthread_args_init(&threads_args[i]);
  }


  //--- PThreads creating ------------------------------------------------------
  threads_args[0].data = data;
  threads_args[0].data_size = data_parts[0];

  size_t success_pthread = 0;

  int errFlag = pthread_create(&threads[0], NULL,
                               (void *(*)(void *))pthread_search_long_word,
                               &threads_args[0]);
  if (errFlag != 0) {
    data_parts[0] = 0;
  } else {
    success_pthread++;
  }

  for(size_t i = 1; i < pthread_count; i++) {
    threads_args[i].data = &data[data_parts[i-1] + 1];
    threads_args[i].data_size = data_parts[i] - data_parts[i-1] - 1;

    errFlag = pthread_create(&threads[i], NULL,
                                 (void *(*)(void *))pthread_search_long_word,
                                 &threads_args[i]);
    if (errFlag != 0) {
      data_parts[i] = 0;
    } else {
      success_pthread++;
    }
  }
  //--- PThreads creating ------------------------------------------------------

  char* longest_word = NULL;
  size_t word_max_len = 0;

  if (success_pthread != 0) {
    void** pthreads_res = malloc(sizeof(void*) * success_pthread);
    size_t joined_pthreads = 0;
    while (joined_pthreads != success_pthread) {
      joined_pthreads = 0;
      for (size_t i = 0; i < success_pthread; i++) {
        if (pthread_join(threads[i], &(pthreads_res[i])) != 0) {
          joined_pthreads++;
        }
      }
    }
    for (size_t i = 0; i < success_pthread; i++) {
      if (threads_args[i].word_len > word_max_len) {
        word_max_len = threads_args[i].word_len;
        longest_word = realloc(longest_word, sizeof(char) * word_max_len);
        memcpy(longest_word, (char*)pthreads_res[i], word_max_len * sizeof(char));
      }
    }

    free(pthreads_res);
  } else {
    longest_word = search_long_word(data, data_length, &word_max_len);
  }

  free(data_parts);
  free(threads);
  free(threads_args);
  free(data);

  *word_length = word_max_len;

  return longest_word;
}
