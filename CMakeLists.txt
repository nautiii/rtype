cmake_minimum_required(VERSION 3.10)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_CXX_STANDARD 17)

project(rtype)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(NO_OUTPUT_DIRS)

add_subdirectory(lib/engine)
add_subdirectory(lib/mediator)
add_subdirectory(lib/system)
add_subdirectory(lib/network)
add_subdirectory(server)
add_subdirectory(client)
add_subdirectory(tests)

enable_testing()
add_test(NAME RtypeTests COMMAND rtype_tests)
