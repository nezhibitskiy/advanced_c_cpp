//
// Created by ilyas on 01.11.2021.
//

#include "searcher.h"

char *search_long_word(char* data, size_t data_size) {
  size_t size = 1;
  char *str = NULL;
  size_t len = 0;
  size_t max_len = 0;
  char *longest_str = NULL;

  if (data == NULL || data_size == 0) {
    return NULL;
  }

  str = realloc(NULL, sizeof(*str)*size); //size is start size

  if(!str) return NULL;

  for (size_t i = 0; i < data_size; i++) {
    while(data[i] != '\n' && i < data_size) {
      str[len++] = data[i];
      if(len == size){
        str = realloc(str, sizeof(*str)*(size+=16));
        if(!str) return NULL;
      }
      i++;
    }
    char* new_str = realloc(str, sizeof(*str)*len);

    if (new_str == NULL) {
      return NULL;
    }
    str = new_str;

    if (len > max_len) {
      longest_str = realloc(NULL, sizeof(*str)*len);
      memcpy(longest_str, str, len);
      max_len = len;
    }
    len = 0;
    size = 1;
    str = realloc(NULL, sizeof(*str)*size); //size is start size
  }

  return longest_str;
}
