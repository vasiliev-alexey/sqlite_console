cmake_minimum_required(VERSION 3.5)
project(sqllite_console)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp managers/ParamsManager.cpp managers/FileManager.cpp managers/DBManager.cpp managers/DBManager.cpp utils/CLog.cpp utils/CLog.h managers/DisplayManager.h managers/ConsoleDisplayManager.cpp managers/ConsoleDisplayManager.h)
add_executable(sqllite_console ${SOURCE_FILES})
