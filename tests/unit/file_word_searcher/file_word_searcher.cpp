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

TEST(FILE_WORD_SEARCHER, READ_FILE) {
  size_t word_length = 0;
  char* data = file_long_word_search(openFilename, &word_length);
  EXPECT_TRUE(data != nullptr);
  const char* real_data = "Word1";
  for (unsigned short i = 0; i < 5; i++) {
    EXPECT_EQ(data[i], real_data[i]);
  }
  free(data);
  EXPECT_EQ(word_length, 5);
}
