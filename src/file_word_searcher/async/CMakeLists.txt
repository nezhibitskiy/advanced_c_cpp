set(LIBRARY_NAME file_word_searcher_parallel)

file(GLOB SRC *.c ../file_word_searcher.h)

add_library(${LIBRARY_NAME} STATIC ${SRC})

target_include_directories(${LIBRARY_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ../.)

target_link_libraries(${LIBRARY_NAME} file_reader searcher)
