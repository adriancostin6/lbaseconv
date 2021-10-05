cmake_minimum_required(VERSION 3.21)

project(baseconv LANGUAGES C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)


#
# Google Test 
#
configure_file(${CMAKE_SOURCE_DIR}/cmake/GoogleTest.cmake.in
    googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
execute_process(COMMAND ${CMAKE_COMMAND} --build .
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )

add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
    ${CMAKE_BINARY_DIR}/googletest-build)

enable_testing()
add_subdirectory(test)

#
# Library sources
#

include_directories("${CMAKE_SOURCE_DIR}/include")

set(SOURCES
    ${CMAKE_SOURCE_DIR}/src/bin2hex.c
    ${CMAKE_SOURCE_DIR}/src/bin2int.c
    ${CMAKE_SOURCE_DIR}/src/bin2oct.c
    ${CMAKE_SOURCE_DIR}/src/dec2bin.c
    ${CMAKE_SOURCE_DIR}/src/dec2hex.c
    ${CMAKE_SOURCE_DIR}/src/dec2oct.c
    ${CMAKE_SOURCE_DIR}/src/hex2bin.c
    ${CMAKE_SOURCE_DIR}/src/hex2dec.c
    ${CMAKE_SOURCE_DIR}/src/hex2oct.c
    ${CMAKE_SOURCE_DIR}/src/oct2bin.c
    ${CMAKE_SOURCE_DIR}/src/oct2dec.c
    ${CMAKE_SOURCE_DIR}/src/oct2hex.c
    ${CMAKE_SOURCE_DIR}/src/util/string.c
    ${CMAKE_SOURCE_DIR}/src/util/invert_string.c
    )

add_library(baseconv ${SOURCES})
target_link_libraries(baseconv m)
