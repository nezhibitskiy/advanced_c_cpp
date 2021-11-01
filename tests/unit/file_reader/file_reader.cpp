//
// Created by cross on 30.10.2021.
//

#include <gtest/gtest.h>
#include <fstream>

extern "C" {
#include "file_reader.h"
#include <stdlib.h>
}

const char* openFilename = "texts/test.txt";
const char* notExistingFilename = "file.txt";


TEST(READ_FILE_TO_MEM, READ_FILE) {
  size_t length = 0;

  char* data = read_file_to_mem(openFilename, &length);

  std::ifstream file;
  file.open(openFilename);
  EXPECT_TRUE(file.is_open());

  file.seekg(0, std::ios::end);
  EXPECT_EQ(length, file.tellg());
  file.seekg(0);

  char tmp = 0;
  for (size_t i = 0; i < length; i++) {
    file.get(tmp);
    EXPECT_EQ(data[i], tmp);
  }

  file.close();
  free(data);
}

TEST(READ_FILE_TO_MEM, SEND_NULL_FILEPATH) {
  size_t length = 0;
  EXPECT_EQ(read_file_to_mem(nullptr, &length), nullptr);
}

TEST(READ_FILE_TO_MEM, SEND_NULL_LENGTH) {
  EXPECT_EQ(read_file_to_mem(openFilename, nullptr), nullptr);
}

TEST(READ_FILE_TO_MEM, READ_NOT_EXISTING_FILENAME) {
  size_t length = 0;
  EXPECT_EQ(read_file_to_mem(notExistingFilename, &length), nullptr);
}