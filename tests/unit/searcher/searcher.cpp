//
// Created by ilyas on 01.11.2021.
//

#include <gtest/gtest.h>

extern "C" {
#include "searcher.h"
}

TEST(SEARCHER, SEND_ZERO_LENGTH) {
  char data = 'C';
  EXPECT_EQ(search_long_word(&data, 0), nullptr);
}

TEST(SEARCHER, SEND_NULL_DATA) {
  EXPECT_EQ(search_long_word(nullptr, 1), nullptr);
}
