cmake_minimum_required(VERSION 3.10)

project(sysspawner)

file(GLOB_RECURSE src *)

include_directories(${CONAN_INCLUDE_DIRS})
include_directories(${CMAKE_INCLUDE_PATH})
include_directories(${rtype_SOURCE_DIR}/lib)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
add_library(sysspawner SHARED ${src})
target_link_libraries(sysspawner ${CONAN_LIBS})