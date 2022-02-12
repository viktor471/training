cmake_minimum_required( VERSION 3.20.1 )

project( listener )

set( CMAKE_CXX_STANDARD 14 )

add_library( ${PROJECT_NAME} STATIC
	${PROJECT_NAME}.cpp
	${PROJECT_NAME}.hpp
)


