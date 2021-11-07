//
// Created by ilyas on 04.11.2021.
//

#include "file_word_searcher.h"

int main() {
  printf("input name of source file: ");
  char* filename = malloc(sizeof(char) * 100);
  if (filename == NULL) {
    return EXIT_FAILURE;
  }

//  filename = "texts/text.txt";
  int scan_return = scanf("%100s", filename);
  if (scan_return == EOF) {
    free(filename);
    return EXIT_FAILURE;
  }

  size_t word_length = 0;
  char* data = file_long_word_search(filename, &word_length);
  if (data == NULL) {
    free(filename);
    return EXIT_FAILURE;
  }

  printf("Longest word in file: ");

  for (size_t i = 0; i < word_length; i++) {
    printf("%c", data[i]);
  }
  printf("\n");

  free(data);
  free(filename);

  return EXIT_SUCCESS;
}
