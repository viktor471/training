cmake_minimum_required( VERSION 3.20.1 )

project( subprojects )

set( SOURCES    main.cpp )
set( SUBLIBNAME sublib   )

include_directories( ${SUBLIBNAME} )

add_executable( a ${SOURCES} )

add_subdirectory( ${SUBLIBNAME} )

target_link_libraries( a ${SUBLIBNAME} )

