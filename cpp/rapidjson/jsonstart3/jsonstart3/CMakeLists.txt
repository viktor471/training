cmake_minimum_required(VERSION 3.0)

project(json_start2 LANGUAGES C CXX)


add_executable(json_start2 main.cpp)

install(TARGETS json_start2 RUNTIME DESTINATION bin)
