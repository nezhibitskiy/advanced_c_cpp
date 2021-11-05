//
// Created by ilyas on 04.11.2021.
//
#include "../file_word_searcher.h"

char* file_long_word_search(const char* filename, size_t* word_length) {
  size_t data_length = 0;
  char* data = read_file_to_mem(filename, &data_length);

  char* longest_word = search_long_word(data, data_length, word_length);

  free(data);

  return longest_word;
}
