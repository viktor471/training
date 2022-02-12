cmake_minimum_required( VERSION 3.14 )

project( hello_world )

include_directories(mylib)

set( A_EXE_SOURCES main.cpp )

add_executable( a ${A_EXE_SOURCES} )

