//
// Created by cross on 28.10.2021.
//

#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

typedef struct pthread_args {
    char* data;
    size_t data_size;
} pthread_args_t;

static char* read_file (size_t* length){
    FILE* file = fopen("../text.txt", "rt");
    fseek(file, 0L, SEEK_END);
    *length = ftell(file);
    rewind(file);
    printf("Size of file is %llu\n", *length);

    char *data = malloc(sizeof(char) * *length);

    if (!data)
        return NULL;

    size_t index = 0;
    for (; index < *length; index++) {
        data[index] = (char)fgetc(file);
    }

    printf("Storaged data length is %llu\n", index);
    fclose(file);

    return data;
};

char *search_long_word(pthread_args_t args) {
    size_t size = 1;
    char *str = NULL;
    size_t len = 0;
    size_t max_len = 0;
    char *longest_str = NULL;

    str = realloc(NULL, sizeof(*str)*size); //size is start size

    if(!str) return NULL;

    for (size_t i = 0; i < args.data_size && args.data[i] != EOF; i++) {
        while(args.data[i] != '\n' && i < args.data_size && args.data[i] != EOF) {
            str[len++] = args.data[i];
            if(len == size){
                str = realloc(str, sizeof(*str)*(size+=16));
                if(!str) return NULL;
            }
            i++;
        }
        realloc(str, sizeof(*str)*len);

        if (len > max_len) {
            longest_str = realloc(NULL, sizeof(*str)*len);
            memcpy(longest_str, str, len);
            max_len = len;
        }
        len = 0;
        size = 1;
        str = realloc(NULL, sizeof(*str)*size); //size is start size
    }

    printf("%s length: %llu\n", longest_str, max_len);
    return longest_str;
}

int main(int argc, char *argv[]) {
    srand(time(NULL));
    int errFlag = 0;
    pthread_t thread; // thread id

    // create and tun POSIX thread
    size_t data_size = 0;
    char* data = read_file(&data_size);
    pthread_args_t args = {data, data_size};
    errFlag = pthread_create(&thread, NULL, search_long_word, &args);
    // check if thread_create call was successful
    if (errFlag != 0) {
        printf("Main: caught error: %d\n", errFlag);
    }
    printf("Main: thread id: %llu\n", thread);
    void* res = NULL;
    while(pthread_join(thread, &res) != 0);
    printf("%s", (char*)res);

    free(data);
    free(res);

    // gracefully exit main thread and associated process
    return EXIT_SUCCESS;
}