//
// Created by cross on 30.10.2021.
//

#ifndef SRC_FILE_READER_FILE_READER_H_
#define SRC_FILE_READER_FILE_READER_H_

#include <stdio.h>
#include <stdlib.h>

char* read_file_to_mem(const char* filepath, size_t* length_buf);

#endif  // SRC_FILE_READER_FILE_READER_H_
