cmake_minimum_required(VERSION 3.5)
project(virtGL)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp includes/Interpreter/ByteCodes/BC.h includes/Interpreter/ByteCodes/BC.cpp includes/Interpreter/CPU/CPU.cpp includes/Interpreter/CPU/CPU.h)
add_executable(virtGL ${SOURCE_FILES})