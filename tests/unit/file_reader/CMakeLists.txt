file(GLOB SRCS *.cpp)

project(file_reader_test)

ADD_EXECUTABLE(${PROJECT_NAME} ${SRCS})

TARGET_LINK_LIBRARIES(${PROJECT_NAME}
        file_reader
        ${GTEST_LIBRARIES}
        Threads::Threads
        )

add_test(NAME ${PROJECT_NAME}
        COMMAND ${PROJECT_NAME})

# file(COPY data/file.txt DESTINATION data)
