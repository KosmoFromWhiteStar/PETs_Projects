cmake_minimum_required(VERSION 3.39)
SET(VCPKG_MANIFEST_INSTALL ON)
SET(VCPKG_MANIFEST_DIR "${CMAKE_SOURCE_DIR}/vcpkg.json")

project(TELEBOT VERSION 0.0.1 LANGUAGES C CXX)
set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}\\scripts\\buildsystems\\vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")
SET(VCPKG_TARGET_TRIPLET x64-mingw-static)
list(APPEND CMAKE_PREFIX_PATH "C:/Library/vcpkg/installed/${VCPKG_TARGET_TRIPLET}")

message("VPKG ${CMAKE_TOOLCHAIN_FILE}")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_subdirectory(${CMAKE_SOURCE_DIR}/INCL)
add_subdirectory(${CMAKE_SOURCE_DIR}/LIBR)


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

