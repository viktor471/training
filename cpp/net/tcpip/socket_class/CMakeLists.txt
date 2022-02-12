cmake_minimum_required(VERSION 3.14)

project(socket_class LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(socket_class STATIC
  socket_class.cpp
  socket_class.h
)

target_compile_definitions(socket_class PRIVATE SOCKET_CLASS_LIBRARY)
