CMAKE_MINIMUM_REQUIRED(VERSION 3.12)

option(test "Build all tests." ON)
option(parallel "Build parallel version" OFF)

project(tp_c_hw2 C CXX)

set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -Wall -Wpedantic -Werror --coverage -pthread")

add_subdirectory(src)
add_subdirectory(cmd)

if(test)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wpedantic -Werror --coverage -pthread")
    set(CMAKE_CXX_STANDARD 11)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)

    set(PROJECT_PATH "${CMAKE_CURRENT_LIST_DIR}")

    add_subdirectory(tests)
    enable_testing()

    find_package(GTest REQUIRED)

endif(test)

unset(test CACHE)
unset(parallel CACHE)