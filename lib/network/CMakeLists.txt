cmake_minimum_required(VERSION 3.10)

project(network)

file(GLOB_RECURSE src *)

include_directories(${CONAN_INCLUDE_DIRS})
include_directories(${CMAKE_INCLUDE_PATH})
include_directories(${rtype_SOURCE_DIR}/lib)

add_library(network ${src})