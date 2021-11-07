CMAKE_MINIMUM_REQUIRED(VERSION 3.12)

option(test "Build all tests." ON)
option(parallel "Build parallel version" OFF)

# Sanitizers
option(address "Add address sanitize" OFF)
option(memory "Add memory sanitize" OFF)
option(undefined "Add undefined sanitize" OFF)
option(thread "Add thread sanitize" OFF)

project(tp_c_hw2 C CXX)

set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -Wall -Wpedantic -Werror --coverage -pthread")

add_subdirectory(src)
add_subdirectory(cmd)

if (address)
    message("Address")
    add_compile_options(-fsanitize=address)
    add_link_options(-fsanitize=address)
elseif(memory)
    message("Memory")
    add_compile_options(-fsanitize=leak)
    add_link_options(-fsanitize=leak)
elseif(undefined)
    message("Undefined")
    add_compile_options(-fsanitize=undefined)
    add_link_options(-fsanitize=undefined)
elseif(thread)
    message("Thread")
    add_compile_options(-fsanitize=thread)
    add_link_options(-fsanitize=thread)
endif()

if(test)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wpedantic -Werror --coverage -pthread")
    set(CMAKE_CXX_STANDARD 11)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)

    set(PROJECT_PATH "${CMAKE_CURRENT_LIST_DIR}")

    enable_testing()

    find_package(GTest REQUIRED)
    include_directories(${GTEST_INCLUDE_DIRS})

    add_subdirectory(tests)
endif(test)

unset(test CACHE)
unset(parallel CACHE)