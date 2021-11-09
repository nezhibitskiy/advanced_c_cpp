//
// Created by ilyas on 04.11.2021.
//

#include "file_generator.h"

int main(int argc, char **argv) {
  if (argc < 4) {
    return EXIT_FAILURE;
  }

  char *end;
  size_t sizeOfFile = strtoul(argv[1], &end, 10);
  if (sizeOfFile == 0) {
    return EXIT_FAILURE;
  }

  size_t maxWordLength = strtoul(argv[2], &end, 10);
  if (maxWordLength == 0) {
    return EXIT_FAILURE;
  }

  return generateFile(sizeOfFile, maxWordLength, argv[3]);
}
