CMAKE_MINIMUM_REQUIRED(VERSION 3.12)

option(test "Build all tests." ON)
option(parallel "Build parallel version" OFF)

project(tp_c_hw2 C CXX)

set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -Wall -Wpedantic -Werror --coverage -pthread")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wpedantic -Werror --coverage -pthread")

add_subdirectory(src)
add_subdirectory(cmd)

if(test)
    set(PROJECT_PATH "${CMAKE_CURRENT_LIST_DIR}")

    add_subdirectory(tests)
    enable_testing()

    include(FetchContent)
    FetchContent_Declare(
            googletest
            # Specify the commit you depend on and update it regularly.
            URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
    )

endif(test)

unset(test CACHE)
unset(parallel CACHE)