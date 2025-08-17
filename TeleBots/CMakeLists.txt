cmake_minimum_required(VERSION 3.39)
project(TELEBOT VERSION 0.0.1 LANGUAGES C CXX)
set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")
list(APPEND CMAKE_PREFIX_PATH "$ENV{VCPKG_ROOT}/installed/x64-windows/share")
message("VPKG $ENV{VCPKG_ROOT}")
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

