cmake_mimimum_required( VERSION 3.20.1 )

project( socket )

set(CMAKE_CXX_STANDARD 14)

add_library( ${PROJECT_NAME} STATIC
	${PROJECT_NAME}.cpp
	${PROJECT_NAME}.hpp
)

