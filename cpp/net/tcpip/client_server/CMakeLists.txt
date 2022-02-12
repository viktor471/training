cmake_minimum_required(VERSION 3.5)

project(client_server LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(GCC_COVERAGE_LINK_FLAGS    "-lresolv")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")
add_executable(client_server main.cpp end_point.cpp server.cpp end_point.hpp server.hpp)
