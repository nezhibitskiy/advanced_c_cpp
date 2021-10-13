// Copyright 2021 Nezhibitskiy Ilyas

#include "pad_array_vectors.h"

void error_free_arr(int ***arr,
                    size_t array_size,
                    size_t vectors_size,
                    size_t current_vector,
                    size_t current_index)
{
  if ((current_vector != 0 || current_index != 0) && vectors_size != 0) {
    for (size_t j = current_index - 1; j + 1 > 0; j--) {
      free(arr[current_vector][j]);
    }
    for (size_t i = current_vector - 1; i + 1 > 0; i--)
      for (size_t j = vectors_size - 1; j + 1 > 0; j--) {
        free(arr[i][j]);
      }
    for (size_t i = current_vector - 1; i + 1 > 0; i--) {
      free(arr[i]);
    }
  }
  if (array_size != 0) free(arr);
}

size_t search_biggest_length(int ***arr, size_t arr_rows_count) {
  size_t size = 1;
  for (size_t i = 0; i < arr_rows_count; i++) {
    if (arr[i] != NULL) {
      if (arr[i][0] != NULL) {
        size_t tmp_size = 1;
        for (; arr[i][tmp_size] != NULL; tmp_size++);
        tmp_size++;
        if (tmp_size > size) size = tmp_size;
      }
    }
  }
  return size;
}

int *alloc_and_init_vector_element(int value) {
  int *element = malloc(sizeof(int));
  if (element == NULL) return NULL;
  *element = value;
  return element;
}

int ***pad_array_vectors(int ***input_arr, size_t arr_rows_count) {
  if (input_arr == NULL) return NULL;

  size_t max_length = search_biggest_length(input_arr, arr_rows_count);

  int ***arr = malloc(sizeof(int **) * arr_rows_count);
  if (arr == NULL) return NULL;

  for (size_t i = 0; i < arr_rows_count; i++) {
    arr[i] = malloc(sizeof(int *) * max_length);
    if (arr[i] == NULL) {
      error_free_arr(arr, arr_rows_count, max_length, i, 0);
      return NULL;
    }
    int8_t flag_of_arr_end = (input_arr[i] == NULL);
    for (size_t j = 0; j < (max_length - 1); j++) {
      if (flag_of_arr_end == 0) {
        if (input_arr[i][j] != NULL) {
          arr[i][j] = alloc_and_init_vector_element(*input_arr[i][j]);
          if (arr[i][j] == NULL) {
            error_free_arr(arr, arr_rows_count, max_length, i, j);
            return NULL;
          }
        }
        else
          flag_of_arr_end = 1;
      }
      if (flag_of_arr_end) {
        arr[i][j] = alloc_and_init_vector_element(0);
        if (arr[i][j] == NULL) {
          error_free_arr(arr, arr_rows_count, max_length, i, j);
          return NULL;
        }
      }
    }

    arr[i][max_length - 1] = NULL;
  }
  return arr;
}
