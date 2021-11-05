set(MAIN_SRCS main.c)

add_executable(main ${MAIN_SRCS})

target_link_libraries(main PUBLIC file_reader searcher)

if(parallel)
    target_link_libraries(main PUBLIC file_word_searcher_parallel)
else()
    target_link_libraries(main PUBLIC file_word_searcher)
endif(parallel)

file(COPY texts/text.txt DESTINATION texts)
