cmake_minimum_required(VERSION 3.13) 
project(MyProject)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    src/main.cpp
    src/Container.cpp
    src/ContainerManager.cpp
    src/TerminalHandler.cpp
    src/TerminalSetValsCmd.cpp
    src/TerminalFillRndCmd.cpp)

add_executable(MyProject ${SOURCES})

target_include_directories(MyProject PRIVATE src)
