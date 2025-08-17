cmake_minimum_required(VERSION 3.39)
SET(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/INCL/bot.hpp" "${CMAKE_SOURCE_DIR}/INCL/Headers.hpp")
SET(SRC_DIR "${CMAKE_SOURCE_DIR}/SRC/bot.cpp")

add_library(bot ${CMAKE_SOURCE_DIR}/SRC/bot.cpp "bot.hpp")
target_include_directories(bot BEFORE PUBLIC "${CMAKE_SOURCE_DIR}/SRC"
    ${CPR_INCLUDE_DIRS})