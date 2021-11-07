//
// Created by ilyas on 01.11.2021.
//

#include "searcher.h"
#include <stdio.h>

char *search_long_word(const char *data, size_t data_size, size_t *max_len) {
  if (data == NULL || data_size == 0 || max_len == NULL) {
    return NULL;
  }

  *max_len = 0;

  char *longest_str = NULL;
  char *str = NULL;

  for (size_t i = 0; i < data_size; i++) {
    size_t size = 1;
    size_t len = 0;

    char *new_str = realloc(str, sizeof(*str) * size);
    if (new_str == NULL) {
      if (i > 0) {
        free(str);
        free(longest_str);
      }
      return NULL;
    }
    str = new_str;
    new_str = NULL;

    while (i < data_size) {
      if (data[i] == ' ') {
        break;
      }
      str[len++] = data[i];
      if (len == size) {
        char *tmp_str;

        tmp_str = realloc(str, sizeof(*str) * (size += 16));
        if (!tmp_str) {
          free(str);
          if (i > 0) {
            free(longest_str);
          }
          return NULL;
        }
        str = tmp_str;
      }
      i++;
    }

    if (len != 0) {
      new_str = realloc(str, sizeof(*str) * len);
      if (!new_str) {
        free(str);
        if (i > 0) {
          free(longest_str);
        }
        return NULL;
      }
      str = new_str;
      new_str = NULL;

      if (len > *max_len) {
        longest_str = realloc(longest_str, sizeof(*str) * len);
        memcpy(longest_str, str, len);
        *max_len = len;
      }
    }
  }

  free(str);

  return longest_str;
}
