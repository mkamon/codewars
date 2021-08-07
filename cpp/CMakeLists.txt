cmake_minimum_required (VERSION 3.0)
project( CODEWARS )

set( PROJECT_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
set( CMAKE_LIBRARY_PATH "${CMAKE_SOURCE_DIR}/src")

add_definitions( "-Wall -pthread -std=c++17 -g" )

add_subdirectory(src)

enable_testing()
include(CTest)
add_subdirectory(ut)
