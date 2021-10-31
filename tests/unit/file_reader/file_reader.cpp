//
// Created by cross on 30.10.2021.
//

#include <gtest/gtest.h>

extern "C" {
#include "file_reader.h"
}

const char* filename = "data/file.txt";

TEST(READ_FILE_TO_MEM, READ_FILE) {
    EXPECT_EQ(1, 1);
}