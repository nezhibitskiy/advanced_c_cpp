CMAKE_MINIMUM_REQUIRED(VERSION 3.13)

project(hw-2)

set(MAIN_SRCS main.c)
set(FILE_GENERATOR_SRCS file_generator.c)
set(READ_FILE_SRCS read_file.c)

add_executable(main ${MAIN_SRCS})
add_executable(file_generator ${FILE_GENERATOR_SRCS})
add_executable(read_file ${READ_FILE_SRCS})
