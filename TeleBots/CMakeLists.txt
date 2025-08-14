cmake_minimum_required(VERSION 3.39)
project(TELEBOT)
set(CMAKE_TOOLCHAIN_FILE "C:/Library/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")
set(VCPKG_TARGET_TRIPLET "x64-mingw-dynamic" CACHE STRING "Vcpkg target triplet")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Typically you don't care so much for a third party library's tests to be
# run from your own project's code.
set(JSON_BuildTests OFF CACHE INTERNAL "")

SET(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/INCL/bot.hpp" "${CMAKE_SOURCE_DIR}/INCL/Headers.hpp")

# If you only include this third party in PRIVATE source files, you do not
# need to install it when your main project gets installed.
# set(JSON_Install OFF CACHE INTERNAL "")
add_subdirectory(${CMAKE_SOURCE_DIR}/LIBR/json)
find_package(cpr REQUIRED)
find_package(CURL REQUIRED)

file(COPY CONF DESTINATION .)
file(COPY LOG DESTINATION .)

add_executable(TeleBot main.cpp ${INCLUDE_DIR})
target_link_libraries(TeleBot PRIVATE 
    nlohmann_json::nlohmann_json
    cpr::cpr
    CURL::libcurl
    ${CMAKE_THREAD_LIBS_INIT}  # Для pthread
)

