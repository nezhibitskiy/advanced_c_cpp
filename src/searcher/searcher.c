//
// Created by ilyas on 01.11.2021.
//

#include "searcher.h"
#include <stdio.h>

char *search_long_word(const char* data, size_t data_size, size_t* max_len) {
  if (data == NULL || data_size == 0 || max_len == NULL) {
    return NULL;
  }

  char *longest_str = NULL;

  for (size_t i = 0; i < data_size; i++) {
    char *str = NULL;
    size_t size = 1;
    size_t len = 0;

    str = realloc(NULL, sizeof(*str)*size); //size is start size
    if(!str) {
      return NULL;
    }

    while(data[i] != ' ' && i < data_size) {
      str[len++] = data[i];
      if(len == size){
        char* tmp_str;
        tmp_str = realloc(str, sizeof(*str)*(size+=16));
        if(!tmp_str) {
          return NULL;
        }
        str = tmp_str;
      }
      i++;
    }

    char* new_str = realloc(str, sizeof(*str)*len);
    if (new_str == NULL) {
      return NULL;
    }
    str = new_str;

    if (len > *max_len) {
      longest_str = realloc(longest_str, sizeof(*str)*len);
      memcpy(longest_str, str, len);
      *max_len = len;
    }
  }

  return longest_str;
}
