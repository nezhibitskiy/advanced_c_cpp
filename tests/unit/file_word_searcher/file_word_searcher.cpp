//
// Created by cross on 04.11.2021.
//

#include <gtest/gtest.h>
#include <fstream>

extern "C" {
#include "file_word_searcher.h"
#include <stdlib.h>
}

const char* openFilename = "texts/test.txt";
//const char* notExistingFilename = "file.txt";

TEST(FILE_WORD_SEARCHER, READ_FILE) {
  size_t word_length = 0;
  char* data = file_long_word_search(openFilename, &word_length);
  const char* real_data = "Word1";
  for (unsigned short i = 0; i < 5; i++) {
    EXPECT_EQ(data[i], real_data[i]);
  }
  free(data);
}

//TEST(READ_FILE_TO_MEM, SEND_NULL_FILEPATH) {
//  size_t length = 0;
//  EXPECT_EQ(read_file_to_mem(nullptr, &length), nullptr);
//}
//
//TEST(READ_FILE_TO_MEM, SEND_NULL_LENGTH) {
//  EXPECT_EQ(read_file_to_mem(openFilename, nullptr), nullptr);
//}
//
//TEST(READ_FILE_TO_MEM, READ_NOT_EXISTING_FILENAME) {
//  size_t length = 0;
//  EXPECT_EQ(read_file_to_mem(notExistingFilename, &length), nullptr);
//}