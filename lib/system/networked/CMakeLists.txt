cmake_minimum_required(VERSION 3.10)

project(sysnetworked)

file(GLOB_RECURSE src *)

include_directories(${rtype_SOURCE_DIR}/lib)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
add_library(sysnetworked SHARED ${src})