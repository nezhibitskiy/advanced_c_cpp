//
// Created by cross on 30.10.2021.
//

#include "file_reader.h"

static size_t get_file_length(FILE *file) {
  if (file == NULL) {
    return 0;
  }

  fseek(file, 0L, SEEK_END);
  size_t length = ftell(file);
  rewind(file);

  return length;
}

char *read_file_to_mem(const char *filepath, size_t *length_buf) {
  if (filepath == NULL || length_buf == NULL) {
    return NULL;
  }

  FILE *file = fopen(filepath, "rt");
  if (file == NULL) {
    return NULL;
  }

  *length_buf = get_file_length(file);
  if (*length_buf == 0) {
    return NULL;
  }

  char *data = malloc(sizeof(char) * *length_buf);
  if (!data) {
    return NULL;
  }

  size_t index = 0;
  for (; index < *length_buf; index++) {
    data[index] = (char)fgetc(file);
  }

  fclose(file);
  return data;
}
