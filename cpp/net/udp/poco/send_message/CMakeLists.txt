cmake_minimum_required(VERSION 3.5)

project(send_message LANGUAGES CXX)

set(GCC_COVERAGE_LINK_FLAGS "-lPocoNet -lPocoUtil")

set(CMAKE_EXE_LINKER_FLAGS  ${CMAKE_EXE_LINKER_FLAGS}
                            ${GCC_COVERAGE_LINK_FLAGS})


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(send_message main.cpp)
