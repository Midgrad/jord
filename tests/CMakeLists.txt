# CMake version string
cmake_minimum_required(VERSION 3.0)

# Project
project(test_jord)

# Executable
file(GLOB SOURCES "*.h" "*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})

# Includes
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Link Libraries
target_link_libraries(${PROJECT_NAME} PRIVATE gtest pthread jord)

# Tests
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
