file(GLOB SRCS *.cpp)

project(searcher_test)

add_executable(${PROJECT_NAME} ${SRCS})

target_link_libraries(${PROJECT_NAME}
                      searcher
                      ${GTEST_LIBRARIES}
                      gtest_main)

add_test(NAME ${PROJECT_NAME}
        COMMAND ${PROJECT_NAME})
