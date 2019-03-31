cmake_minimum_required(VERSION 3.9 FATAL_ERROR)

project(Observer)

include_directories(SYSTEM ${PROJECT_SOURCE_DIR})
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

option(OBSERVER_BUILD_EXAMPLES "Build examples" ON)

add_library(Observer SHARED observer.h)
target_include_directories(Observer SYSTEM PRIVATE)
target_compile_definitions(Observer PUBLIC OBSERVER_SHARED PRIVATE OBSERVER_SHARED_EXPORTS)
set_target_properties(Observer PROPERTIES LINKER_LANGUAGE CXX)

if (OBSERVER_BUILD_EXAMPLES)

add_executable(ObserverTest
    example.cpp)
  target_link_libraries(ObserverTest Observer)

endif ()
