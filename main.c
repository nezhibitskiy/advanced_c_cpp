//
// Created by cross on 28.10.2021.
//
#define _CRT_RAND_S

#include <stdio.h>
#include <stdlib.h>

// char symbols: A-Z: 65-90 a-z: 97-122
// Sum: 26+26 = 52
// Rand max 52

int main() {


//    file = fopen("../text.txt", "rt");
////    size_t size = 1;
////    char *str;
////    int ch;
////    size_t len = 0;
////    str = realloc(NULL, sizeof(*str)*size);//size is start size
////    if(!str)return -1;
////    while(EOF!=(ch=fgetc(file)) && ch != '\n'){
////        str[len++] = (char)ch;
////        if(len==size){
////            str = realloc(str, sizeof(*str)*(size+=16));
////            if(!str) return -1;
////        }
////    }
////    realloc(str, sizeof(*str)*len);
////
////    printf("%s length: %llu", str, len);
//
//    size_t max_len = 0;
//    size_t len = 0;
//    int ch = 0;
//    while(ch!=EOF){
//        while (ch != ' ' && ch!=EOF) {
//            ch=fgetc(file);
//            len++;
//        }
//        if (len > max_len)
//            max_len = len;
//        len = 0;
//        ch=fgetc(file);
//    }
//    fclose(file);
//
//    printf("Origin max length: %llu; Calculated: %llu", original_max_len, max_len);


//    FILE* file = fopen("../text.txt", "rt");
//    fseek(file, 0L, SEEK_END);
//    size_t sz = ftell(file);
//    rewind(file);
//    printf("Size of file is %llu\n", sz);
//    printf("%c%c%c", fgetc(file), fgetc(file), fgetc(file));
//    fclose(file);
//    size_t process_count = 4;//sysconf(_SC_NPROCESSORS_ONLN);


    return 0;
}

//#include <stdlib.h> // EXIT_SUCCESS
//#include <pthread.h>
//#include <stdio.h>
//#include <time.h>
//#include <unistd.h>
//
//#define MAX_SLEEP_TIME 5
//
//void rand_sleep(char *whoami) {
//    int sleep_time = 1 + rand() % MAX_SLEEP_TIME;
//    printf("%s: sleeping for %d seconds...\n", whoami, sleep_time);
//    sleep(sleep_time);
//}
//
//void *thread_routine(void *arg) {
//    int errflag = 0;
//    // ...
//    // detach from main process as a POSIX thread until the end
//    errflag = pthread_detach(pthread_self());
//    // check if pthread_detach() call was successful
//    if (errflag != 0) {
//        printf("Thread: caught error: %d\n", errflag);
//    }
//    rand_sleep("Thread");
//    printf("Thread: hello!\n");
//    // gracefully exit thread with void *value as a result
//    return arg; // another variant: return NULL etc
//}
//
//int main(int argc, char *argv[]) {
//    srand(time(NULL));
//    int errflag = 0;
//    pthread_t thread; // thread id
//
//    // create and tun POSIX thread
//    errflag = pthread_create(&thread, NULL, thread_routine, NULL);
//    // check if thread_create call was successful
//    if (errflag != 0) {
//        printf("Main: caught error: %d\n", errflag);
//    }
//    rand_sleep("Main");
//    printf("Main: thread id: %ld\n", thread);
//    // pthread_exit(0);
//    // gracefully exit main thread and associated process
//    return EXIT_SUCCESS;
//}