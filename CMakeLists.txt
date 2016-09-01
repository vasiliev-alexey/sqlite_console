cmake_minimum_required(VERSION 3.5)
project(sqllite_console)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp utils.cpp FileManager.cpp)
add_executable(sqllite_console ${SOURCE_FILES})
