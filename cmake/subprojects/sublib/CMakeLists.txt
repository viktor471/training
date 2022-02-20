cmake_minimum_required( VERSION 3.1.20 )

set( PROJECT_NAME sublib )

set( SOURCES sublib.cpp )

add_library( ${PROJECT_NAME} STATIC ${SOURCES} )
