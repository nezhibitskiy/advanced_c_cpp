//
// Created by ilyas on 01.11.2021.
//

#include <gtest/gtest.h>

extern "C" {
#include "searcher.h"
}

TEST(SEARCHER, SEND_ZERO_LENGTH) {
  char data = 'C';
  size_t max_len = 0;
  EXPECT_EQ(search_long_word(&data, 0, &max_len), nullptr);
}

TEST(SEARCHER, SEND_NULL_DATA) {
  size_t max_len = 0;
  EXPECT_EQ(search_long_word(nullptr, 1, &max_len), nullptr);
}

TEST(SEARCHER, SEND_NULL_MAX_LEN) {
  char data = 'C';
  EXPECT_EQ(search_long_word(&data, 1, nullptr), nullptr);
}

TEST(SEARCHER, SMALL_DATA) {
  char data[] = "Word Word1 Word2";
  size_t max_len = 0;

  char* receivedData = search_long_word(data, 16, &max_len);
  EXPECT_TRUE(receivedData);
  EXPECT_EQ(max_len, 5);

  EXPECT_EQ(receivedData[0], 'W');
  EXPECT_EQ(receivedData[1], 'o');
  EXPECT_EQ(receivedData[2], 'r');
  EXPECT_EQ(receivedData[3], 'd');
  EXPECT_EQ(receivedData[4], '1');
}

TEST(SEARCHER, ONE_WORD) {
  char data[] = "W";
  size_t max_len = 0;

  char* receivedData = search_long_word(data, 1, &max_len);
  EXPECT_TRUE(receivedData);
  EXPECT_EQ(max_len, 1);

  EXPECT_EQ(receivedData[0], 'W');
}
