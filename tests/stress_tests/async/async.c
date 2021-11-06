//
// Created by ilyas on 06.11.2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "file_word_searcher.h"

const char* filename = "../texts/text.txt";

int main()
{
  char* data = NULL;
  size_t word_length = 0;

  struct timespec start, finish;
  double elapsed;

  clock_gettime(CLOCK_MONOTONIC, &start);

  data = file_long_word_search(filename, &word_length);

  clock_gettime(CLOCK_MONOTONIC, &finish);

  elapsed = (finish.tv_sec - start.tv_sec);
  elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;

//  printf("Longest word in file: ");
//
//  for (size_t i = 0; i < word_length; i++) {
//    printf("%c", data[i]);
//  }
//  printf("\n");

  free(data);

  printf("%f\n", elapsed);

  return 0;
}
