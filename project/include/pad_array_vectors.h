// Copyright 2021 Nezhibitskiy Ilyas

#ifndef PROJECT_INCLUDE_PAD_ARRAY_VECTORS_H_
#define PROJECT_INCLUDE_PAD_ARRAY_VECTORS_H_

#include <stdlib.h>
#include <string.h>

size_t search_length(int ***arr, size_t arr_rows_count);
int *addElementToVector(int value);
int ***update_matrix(int ***input_arr, size_t arr_rows_count);

#endif  // PROJECT_INCLUDE_PAD_ARRAY_VECTORS_H_
