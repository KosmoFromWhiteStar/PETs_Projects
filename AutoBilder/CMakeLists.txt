cmake_minimum_required(VERSION 4.0.0)
project("AutoBilder")

FILE(COPY ${CMAKE_SOURCE_DIR}/test_dir DESTINATION ${CMAKE_BINARY_DIR})

add_executable(${PROJECT_NAME} main.cpp)