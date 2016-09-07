cmake_minimum_required(VERSION 3.5)
project(sqllite_console)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES
        main.cpp
        managers/ParamsManager.cpp
        managers/FileManager.cpp
        managers/DBManager.cpp
        managers/DBManager.cpp
        utils/CLog.cpp
        utils/CLog.h
        managers/DisplayManager.h
        managers/ConsoleDisplayManager.cpp
        managers/ConsoleDisplayManager.h
        managers/FileOutPutManager.cpp
        managers/FileOutPutManager.h)
add_executable(sqllite_console ${SOURCE_FILES})

set(LIB_PATHS /usr/lib
        }
        )
find_library(SQLITE_LIBRARY
        NAMES sqlite3
        PATHS ${LIB_PATHS})
target_link_libraries(sqllite_console ${SQLITE_LIBRARY})




