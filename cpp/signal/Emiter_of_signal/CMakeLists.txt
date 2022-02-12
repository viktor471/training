cmake_minimum_required(VERSION 3.5)

project(Emiter_of_signal LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

FIND_PACKAGE(PkgConfig REQUIRED)

include_directories(${SIGC++_INCLUDE_DIRS})
link_directories(${SIGC++_LIBRARY_DIRS})
link_libraries(${SIGC++_LIBRARIES} pthread)

pkg_check_modules(SIGC++ REQUIRED sigc++-2.0)

add_executable(Emiter_of_signal main.cpp)
