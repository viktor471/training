cmake_minimum_required( VERSION 3.14 )

project( hello_world )

set( A_EXE_SOURCES main.cpp )
set( MYLIB_SOURCES mylib.cpp  )

add_library( mylib STATIC ${MYLIB_SOURCES} )

add_executable( a ${A_EXE_SOURCES} )

target_link_libraries( a mylib )
