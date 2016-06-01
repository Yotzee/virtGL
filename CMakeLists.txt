cmake_minimum_required(VERSION 3.5)
project(virtGL)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp includes/Interpreter/CPU/CPU.cpp includes/Interpreter/CPU/CPU.h includes/Interpreter/Globals.h includes/Interpreter/includes.h includes/Interpreter/Instructions/Math/Integer.h includes/Interpreter/Instructions/Math/Float.h includes/Interpreter/Instructions/Math/Double.h includes/Interpreter/Instructions/System/System.h includes/Interpreter/Instructions/System/Print.h)
add_executable(virtGL ${SOURCE_FILES})