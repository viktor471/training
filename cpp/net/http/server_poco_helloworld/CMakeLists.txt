cmake_minimum_required(VERSION 3.5)

project(server_poco_helloworld LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(GCC_COVERAGE_LINK_FLAGS "-lPocoNet -lPocoUtil")

set(CMAKE_EXE_LINKER_FLAGS  ${CMAKE_EXE_LINKER_FLAGS}
                            ${GCC_COVERAGE_LINK_FLAGS})

set(EXEC_DIRECTORY  "./exec")
set(SOURCES_FOLDER  "./sources")

set(HEADER_FILES    ${SOURCES_FOLDER}/server.hpp)

set(SOURCES         main.cpp
                    ${SOURCES_FOLDER}/server.cpp)


add_executable(server_poco_helloworld  ${HEADER_FILES}
                                       ${SOURCES} )

target_include_directories(server_poco_helloworld PRIVATE ${SOURCES_FOLDER})
