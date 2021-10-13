// Copyright 2021 Nezhibitskiy Ilyas

#include "pad_array_vectors.h"

static size_t search_length(int ***arr, size_t arr_rows_count) {
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

static int *alloc_and_init_vector_element(int value) {
  int *element = malloc(sizeof(int));
  *element = value;
  return element;
}

int ***update_matrix(int ***input_arr, size_t arr_rows_count) {
  size_t max_length = search_length(input_arr, arr_rows_count);

  int ***arr = malloc(sizeof(int **) * arr_rows_count);
  for (size_t i = 0; i < arr_rows_count; i++) {
    arr[i] = malloc(sizeof(int *) * max_length);
    int8_t flag_of_arr_end = (input_arr[i] == NULL);
    for (size_t j = 0; j < (max_length - 1); j++) {
      if (flag_of_arr_end == 0) {
        if (input_arr[i][j] != NULL)
          arr[i][j] = alloc_and_init_vector_element(*input_arr[i][j]);
        else
          flag_of_arr_end = 1;
      }
      if (flag_of_arr_end) {
        arr[i][j] = alloc_and_init_vector_element(0);
      }
    }

    arr[i][max_length - 1] = NULL;
  }
  return arr;
}
