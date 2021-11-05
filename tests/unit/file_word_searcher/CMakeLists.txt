file(GLOB SRCS *.cpp)

project(file_word_searcher_test)

add_executable(${PROJECT_NAME} ${SRCS})

target_link_libraries(${PROJECT_NAME}
        file_word_searcher
        ${GTEST_LIBRARIES}
        gtest_main)

add_test(NAME ${PROJECT_NAME}
        COMMAND ${PROJECT_NAME})

file(COPY texts/test.txt DESTINATION texts)
