cmake_minimum_required(VERSION 3.10)

project(r-type_server)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(NO_OUTPUT_DIRS)


include_directories(include)
include_directories(src)
include_directories(src/network)
include_directories(src/protocol)
include_directories(../lib/network)
include_directories(${rtype_SOURCE_DIR}/lib)

add_executable(r-type_server
    src/main.cpp
    src/Server.cpp
    src/network/Gateway.cpp
    src/network/Room.cpp
    src/network/Session.cpp
    src/Getopt.cpp
    src/protocol/Interpreter.cpp
)

target_link_libraries(r-type_server ${CONAN_LIBS} network)