cmake_minimum_required(VERSION 3.22)
project(AnimatedGraph)

set(CMAKE_CXX_STANDARD 17)
find_package(SDL2 REQUIRED)
include_directories(AnimatedGraph ${SDL2_INCLUDE_DIRS})

add_library(myLib
        lib/src/Display.cpp
        lib/include/Display.h)
target_include_directories(myLib PRIVATE lib/include)

add_executable(AnimatedGraph main.cpp)
target_include_directories(AnimatedGraph PRIVATE lib/include)
target_link_libraries(AnimatedGraph myLib ${SDL2_LIBRARIES})