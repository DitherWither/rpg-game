cmake_minimum_required(VERSION 3.25)
project(rpg_game)
#find_package(raylib 3.0 REQUIRED) # Requires at least version 3.0

include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz)
FetchContent_MakeAvailable(json)

FetchContent_Declare(raylib URL https://github.com/raysan5/raylib/archive/refs/tags/4.5.0.tar.gz)
FetchContent_MakeAvailable(raylib)

set(CMAKE_CXX_STANDARD 23)

add_executable(rpg_game src/main.cpp src/Game.cpp src/Game.hpp src/Player.cpp src/Player.hpp src/Tileset.cpp src/Tileset.hpp src/Map.cpp src/Map.hpp)

target_link_libraries(rpg_game PUBLIC raylib)
target_link_libraries(rpg_game PRIVATE nlohmann_json::nlohmann_json)

add_custom_command(TARGET rpg_game PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E create_symlink
        ${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:rpg_game>/assets)

# Checks if OSX and links appropriate frameworks (only required on MacOS)
if (APPLE)
    target_link_libraries(main "-framework IOKit")
    target_link_libraries(main "-framework Cocoa")
    target_link_libraries(main "-framework OpenGL")
endif()
