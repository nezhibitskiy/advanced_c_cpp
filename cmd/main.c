//
// Created by ilyas on 04.11.2021.
//

#include "file_word_searcher.h"

int main()
{
//  printf("input name of source file: ");
  char* filename = malloc(sizeof(char) * 100);
  if (filename == NULL) {
    return EXIT_FAILURE;
  }

  filename = "texts/text.txt";
//  int scan_return = scanf("%s", filename);
//  if (scan_return == EOF) {
//    return EXIT_FAILURE;
//  }

  char* data = NULL;
  data = file_long_word_search(filename);
  if (data == NULL) {
    return EXIT_FAILURE;
  }

  printf("Longest word in file: ");

  for (unsigned short i = 0; i < 201; i++) {
    printf("%c", data[i]);
  }
  printf("\n");

  free(data);

  return EXIT_SUCCESS;
}
