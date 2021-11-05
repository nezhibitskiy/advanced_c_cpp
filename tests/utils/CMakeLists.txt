set(LIBRARY_NAME file_generator)

file(GLOB SRC file_generator.h file_generator.cpp)

add_library(${LIBRARY_NAME} STATIC ${SRC})

target_include_directories(${LIBRARY_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(file_gen main.cpp)

target_link_libraries(file_gen ${LIBRARY_NAME})
