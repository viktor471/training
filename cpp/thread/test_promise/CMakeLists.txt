cmake_minimum_required(VERSION 3.5)

project(test_promise LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package( Catch2  REQUIRED )
find_package( Threads REQUIRED )

set(LIBS PRIVATE Catch2::Catch2 Threads::Threads )

add_executable( test_promise main.cpp )
target_link_libraries( test_promise ${LIBS} )


