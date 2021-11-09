//
// Created by ilyas on 01.11.2021.
//

#include <random>

#include "file_generator.h"

#define LETTERS_COUNT 26
#define LETTERS_ASCII_OFFSET 64
#define LETTERS_LOWER_CASE_OFFSET 6

int generateFile(size_t size, size_t reqMaxWordLength,
                 const std::string &filename) {
  size_t original_max_len = 0;
  std::ofstream file;

  file.open(filename);
  if (!file.is_open()) {
    return -1;
  }

  size_t i = 0;
  while (i < size) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist1(1, reqMaxWordLength);
    // Rand from lower and upper letters cases (multiply two)
    std::uniform_int_distribution<int> dist2(1, LETTERS_COUNT * 2);

    unsigned int word_length = dist1(mt);
    if (word_length > original_max_len) {
      original_max_len = word_length;
    }

    for (unsigned int j = 0; j < word_length && i < size; j++) {
      unsigned int letter_number = dist2(mt);

      if (letter_number > LETTERS_COUNT) {
        letter_number += LETTERS_LOWER_CASE_OFFSET;
      }
      letter_number += LETTERS_ASCII_OFFSET;

      file << static_cast<char>(letter_number);
      i++;
    }
    file << " ";
  }
  file.close();
  return original_max_len;
}
