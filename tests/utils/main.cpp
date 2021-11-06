//
// Created by ilyas on 04.11.2021.
//

#include "file_generator.h"

int main() {
  std::string filename = "./../stress_tests/texts/text.txt";
  return generateFile(100000000, 221, filename);
}
