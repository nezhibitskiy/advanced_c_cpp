file(GLOB SRCS *.c)

project(stress_async_test)

add_executable(${PROJECT_NAME} ${SRCS})

target_link_libraries(${PROJECT_NAME} PUBLIC file_reader searcher file_word_searcher_parallel)
