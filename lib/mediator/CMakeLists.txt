cmake_minimum_required(VERSION 3.10)

project(mediator)

file(GLOB_RECURSE src *)

include_directories(${CMAKE_INCLUDE_PATH})
include_directories(${rtype_SOURCE_DIR}/lib)

add_library(mediator SHARED ${src})