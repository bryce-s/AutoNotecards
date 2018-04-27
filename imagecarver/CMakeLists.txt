cmake_minimum_required(VERSION 3.8)
project(imagecarver)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp src/Settings.cpp src/Settings.h src/ImageTargets.cpp src/ImageTargets.h src/PageVertex.cpp src/PageVertex.h)
add_executable(imagecarver ${SOURCE_FILES})