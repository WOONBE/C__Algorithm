cmake_minimum_required(VERSION 3.25)
project(C__Algorithm)

set(CMAKE_CXX_STANDARD 17)


add_executable(main main.cpp)
add_executable(normal chapter2/normal.cpp chapter2)
add_executable(fastsum chapter2/fastsum.cpp)