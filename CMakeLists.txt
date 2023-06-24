cmake_minimum_required(VERSION 3.25)
project(C__Algorithm)

set(CMAKE_CXX_STANDARD 17)


add_executable(main main.cpp chapter3/alphabet.cpp chapter3/roomnumber.cpp)
add_executable(normal chapter2/normal.cpp chapter2)
add_executable(fastsum chapter2/fastsum.cpp chapter3/array.cpp chapter3/array.h)
add_executable(array chapter3/array.cpp)
add_executable(alphabet chapter3/alphabet.h chapter3/alphabet.cpp chapter3/roomnumber.cpp)
add_executable(roomnumber chapter3/roomnumber.cpp)
add_executable(linkedlist chapter4/linkedlist.cpp)
add_executable(editor chapter4/editor.cpp)
add_executable(stack chapter5/stack.cpp)