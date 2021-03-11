cmake_minimum_required(VERSION 3.10)

project(r-type_client)

file(GLOB_RECURSE src src/*)

include_directories(${CONAN_INCLUDE_DIRS})
include_directories(${CMAKE_INCLUDE_PATH})
include_directories(src/)
include_directories(src/scene)
include_directories(${rtype_SOURCE_DIR}/lib)
include_directories(${rtype_SOURCE_DIR}/lib/network)

add_executable(r-type_client ${src})

target_link_libraries(r-type_client engine ${CONAN_LIBS} network)
file(COPY ressources DESTINATION ${CMAKE_BINARY_DIR})
file(COPY config DESTINATION ${CMAKE_BINARY_DIR})