cmake_minimum_required(VERSION 3.10)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(NO_OUTPUT_DIRS)

include_directories(${rtype_SOURCE_DIR}/lib)

include_directories(${CONAN_INCLUDE_DIRS})
include_directories(${CMAKE_INCLUDE_PATH})

add_executable(rtype_tests unit_tests.cpp)
target_link_libraries(rtype_tests ${CONAN_LIBS} network)
