//
// Created by ilyas on 06.11.2021.
//

#include <stdio.h>
#include <time.h>

#include "file_word_searcher.h"

#define NANOSEC_IN_SEC 1000000000.0F

const char *filename = "../texts/text.txt";

int main() {

  char *data = NULL;
  size_t word_length = 0;

  struct timespec start, finish;
  double elapsed;

  clock_gettime(CLOCK_MONOTONIC, &start);

  data = file_long_word_search(filename, &word_length);

  clock_gettime(CLOCK_MONOTONIC, &finish);

  elapsed = (double)(finish.tv_sec - start.tv_sec);
  elapsed += (double)(finish.tv_nsec - start.tv_nsec) / NANOSEC_IN_SEC;

  free(data);

  printf("%f\n", elapsed);

  return 0;
}
