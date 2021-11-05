//
// Created by ilyas on 01.11.2021.
//

#include "file_generator.h"
#include <random>

// char symbols: A-Z: 65-90 a-z: 97-122
// Sum: 26+26 = 52
// Rand max 52

int generateFile(size_t size, size_t reqMaxWordLength, std::string filename) {
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
    std::uniform_int_distribution<int> dist2(1, 52);

    unsigned int word_length = dist1(mt);
    if (word_length > original_max_len) {
      original_max_len = word_length;
    }

    for (unsigned int j = 0; j < word_length && i < size; j++) {
      unsigned int letter_number = dist2(mt);

      if (letter_number > 26) {
        letter_number += 6;
      }
      letter_number += 64;

      file << static_cast<char>(letter_number);
      i++;
    }
    file << "\n";
  }
  file.close();
  return original_max_len;
}
