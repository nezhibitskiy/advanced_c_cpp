file(GLOB SRCS *.cpp)

project(file_reader_test)

add_executable(${PROJECT_NAME} ${SRCS})

target_link_libraries(${PROJECT_NAME}
                      file_reader
                      ${GTEST_LIBRARIES}
                      gtest_main)

add_test(NAME ${PROJECT_NAME}
        COMMAND ${PROJECT_NAME})
# file(COPY data/file.txt DESTINATION data)
