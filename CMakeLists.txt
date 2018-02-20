cmake_minimum_required(VERSION 3.9)

project(Observer)

INCLUDE_DIRECTORIES(SYSTEM ${PROJECT_SOURCE_DIR})
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(${PROJECT_NAME}
    main.cpp
    observer.h
    observer.cpp)
