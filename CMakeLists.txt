cmake_minimum_required(VERSION 3.12.4)
project(advanced_c_c___homeworks C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LIB_SOURCE_FILES padArrayVectors.c)
add_library(padArrayVectors STATIC ${LIB_SOURCE_FILES})

# add_executable(advanced_c_c___homeworks main.c)
# target_link_libraries(advanced_c_c___homeworks padArrayVectors)

enable_testing()
find_package(GTest REQUIRED)

project(hw_tests)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${GTEST_INCLUDE_DIRS})
add_executable(hw_test hw_test.cpp)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
target_link_libraries(hw_test ${GTEST_LIBRARIES} padArrayVectors)