#include <stdio.h>
#include <stdlib.h>
#include "pad_array_vectors.h"

void error_free_raw_arr(int ***arr,
                        size_t array_size,
                        size_t *vectors_size,
                        size_t current_vector,
                        size_t current_index)
{
  if ((current_vector != 0 || current_index != 0) && vectors_size != NULL) {
    for (size_t j = current_index - 1; j + 1 > 0; j--) {
      frprintf("Free %zu data from %zu vector\n", j, current_vector);
      free(arr[current_vector][j]);
    }
    for (size_t i = current_vector - 1; i + 1 > 0; i--)
      for (size_t j = vectors_size[i] - 1; j + 1 > 0; j--) {
        frprintf("Free %zu data from %zu vector\n", j, i);
        free(arr[i][j]);
      }
    for (size_t i = current_vector - 1; i + 1 > 0; i--) {
      frprintf("Free %zu vector\n", i);
      free(arr[i]);
    }
  }
  frprintf("Free array\n");
  if (array_size != 0) free(arr);
}

int main() {
  size_t array_size = 0;

  while (array_size == 0) {
    printf("Write size of array of vectors: ");
    scanf("%zu", &array_size);
    if (array_size == 0) printf("Write correct size of array\n");
  }

  int ***arr = malloc(sizeof(int **) * array_size);

  if (arr == NULL) {
    frprintf("Error during allocating memory for array of vectors");
    error_free_raw_arr(arr, array_size, NULL, 0, 0);
    return EXIT_FAILURE;
  }

  size_t *vector_sizes = malloc(sizeof(size_t) * array_size);
  if (vector_sizes == NULL) {
    frprintf("Error during allocating memory for array of vector sizes\n");
    error_free_raw_arr(arr, array_size, NULL, 0, 0);
    return EXIT_FAILURE;
  }
  for(size_t i = 0; i < array_size; i++) vector_sizes[i] = 0;

  size_t biggest_vector = 0;

  for (size_t i = 0; i < array_size; i++) {
    printf("Write size of %zu vector: ", i + 1);
    scanf("%zu", &vector_sizes[i]);
    if (vector_sizes[i] > biggest_vector) biggest_vector = vector_sizes[i];
    arr[i] = malloc(sizeof(int*) * (vector_sizes[i] + 1));
    if (arr[i] == NULL) {
      frprintf("Error during allocating memory for vector\n");
      error_free_raw_arr(arr, array_size, vector_sizes, i, 0);
      free(vector_sizes);
      return EXIT_FAILURE;
    }
    for (size_t j = 0; j < vector_sizes[i]; j++) {
      printf("Write value of %zu item %zu vector: ", j + 1, i + 1);
      int tmp_value = 0;
      scanf("%d", &tmp_value);
      arr[i][j] = malloc(sizeof(int));
      if (arr[i][j] == NULL) {
        frprintf("Error during allocating memory for data\n");
        error_free_raw_arr(arr, array_size, vector_sizes, i, j);
        free(vector_sizes);
        return EXIT_FAILURE;
      }
      *arr[i][j] = tmp_value;
    }
    arr[i][vector_sizes[i]] = NULL;
  }

  int*** returned_arr = pad_array_vectors(arr, array_size);

  for (size_t i = 0; i < array_size; i++) {
    for (size_t j = 0; j < vector_sizes[i]; j++) {
      free(arr[i][j]);
    }
    free(arr[i]);
  }
  free(arr);

  if (returned_arr == NULL) {
    frprintf("Error of padding elements to vectors\n");
    free(vector_sizes);
    return EXIT_FAILURE;
  }

  for (size_t i = 0; i < array_size; i++)
  {
    for (size_t j = 0; j < biggest_vector; j++) {
      printf("%d", *returned_arr[i][j]);
      free (returned_arr[i][j]);
    }
    free(returned_arr[i]);
    printf("\n");
  }
  free(returned_arr);

  free(vector_sizes);

  return EXIT_SUCCESS;
}
