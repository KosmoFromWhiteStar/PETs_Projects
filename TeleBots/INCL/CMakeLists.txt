cmake_minimum_required(VERSION 3.39)
SET(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/INCL/bot.hpp" "${CMAKE_SOURCE_DIR}/INCL/Headers.hpp" 
    "greeter.h" "log.h" "bot_function.hpp")
SET(SRC_DIR "${CMAKE_SOURCE_DIR}/SRC/bot.cpp"
    "${CMAKE_SOURCE_DIR}/SRC/log.cpp"    
    "${CMAKE_SOURCE_DIR}/SRC/bot_function.cpp")

include_directories(BEFORE PUBLIC "${CMAKE_SOURCE_DIR}/SRC"
    ${CPR_INCLUDE_DIRS})

add_library(bot ${INCLUDE_DIR} ${SRC_DIR})

target_link_libraries(bot PUBLIC
    nlohmann_json::nlohmann_json
    cpr::cpr
    CURL::libcurl
    ${CMAKE_THREAD_LIBS_INIT}  # Для pthread
)