cmake_minimum_required(VERSION 3.10)
project(AStarLabSDL)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

add_subdirectory(test)

set(SOURCE_FILES Game.cpp Game.h TextureManager.h TextureManager.cpp GameObject.cpp GameObject.h Map.cpp Map.h Enemy.cpp Enemy.h MapSearchNode.h MapSearchNode.cpp)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})
include_directories(${SDL2_INCLUDE_DIR})
set(SDL_LIBRARY_TEMP ${SDL2_LIBRARY})


add_executable(AStarLabSDL main.cpp Game.cpp Game.h TextureManager.h TextureManager.cpp GameObject.cpp GameObject.h Map.cpp Map.h Enemy.cpp Enemy.h MapSearchNode.h MapSearchNode.cpp fsa.h stlastar.h)

target_link_libraries(AStarLabSDL core)
target_link_libraries(AStarLabSDL ${SDL2_LIBRARY_TEMP} ${SDL2_IMAGE_LIBRARIES})
add_library(core ${SOURCE_FILES})
