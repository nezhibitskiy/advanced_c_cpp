CMAKE_MINIMUM_REQUIRED(VERSION 3.14)

option(test "Build all tests." ON)
option(parallel "Build parallel version" ON)

project(tp_c_hw2 C CXX)

set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -Wall -Wpedantic -Werror --coverage -pthread")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wpedantic -Werror --coverage")

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
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)

endif(test)

unset(test CACHE)
unset(parallel CACHE)