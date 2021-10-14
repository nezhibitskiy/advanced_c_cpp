// Copyright 2021 Nezhibitskiy Ilyas

#ifndef PROJECT_INCLUDE_PAD_ARRAY_VECTORS_H_
#define PROJECT_INCLUDE_PAD_ARRAY_VECTORS_H_

#include <stdlib.h>

size_t search_biggest_length(int ***arr, size_t arr_rows_count);
int *alloc_and_init_vector_element(int value);
int ***pad_array_vectors(int ***input_arr, size_t arr_rows_count);

#endif  // PROJECT_INCLUDE_PAD_ARRAY_VECTORS_H_
