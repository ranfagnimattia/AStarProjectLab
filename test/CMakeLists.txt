cmake_minimum_required(VERSION 3.10)

add_subdirectory(./lib/googletest)

set(gtest_SOURCE_DIR, ./lib/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

set(TEST_SOURCE_FILES runAllTests.cpp MapTest.cpp)
add_executable(runGameMapTests ${TEST_SOURCE_FILES})

target_link_libraries(runGameMapTests gtest gtest_main core)
target_link_libraries(runGameMapTests ${SDL2_LIBRARY_TEMP} ${SDL2_IMAGE_LIBRARIES})
