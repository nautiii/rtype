cmake_minimum_required(VERSION 3.10)

project(sysshooter)

file(GLOB_RECURSE src *)

include_directories(${rtype_SOURCE_DIR}/lib)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
add_library(sysshooter SHARED ${src})
target_link_libraries(sysshooter ${CONAN_LIBS})
