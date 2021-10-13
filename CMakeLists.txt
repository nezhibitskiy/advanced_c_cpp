cmake_minimum_required(VERSION 3.12)
project(tp_c_hw1 C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -Wall -Wpedantic -Werror --coverage")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wpedantic -Werror --coverage")

set(LIB_SOURCE_FILES project/src/pad_array_vectors.c)
set(LIB_INCLUDE_FILES project/include/)
include_directories(${LIB_INCLUDE_FILES})
add_library(padArrayVectors STATIC ${LIB_SOURCE_FILES})

# add_executable(advanced_c_c___homeworks main.c)
# target_link_libraries(advanced_c_c___homeworks padArrayVectors)

enable_testing()
find_package(GTest REQUIRED)

project(hw_tests)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${GTEST_INCLUDE_DIRS})
add_executable(hw_test tests/hw_test.cpp)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
target_link_libraries(hw_test ${GTEST_LIBRARIES} padArrayVectors)