cmake_minimum_required(VERSION 3.5)

project(factory LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(EXEC_DIRECTORY  "./exec")
set(SOURCES_FOLDER  "./sources")


set(HEADER_FILES    ${SOURCES_FOLDER}/creator.hpp
                    ${SOURCES_FOLDER}/products.hpp
                    ${SOURCES_FOLDER}/client_code.hpp)

set(SOURCES         main.cpp
                    ${SOURCES_FOLDER}/creator.cpp
                    ${SOURCES_FOLDER}/products.cpp
                    ${SOURCES_FOLDER}/client_code.cpp)

add_executable(factory  ${HEADER_FILES}
                        ${SOURCES} )


target_include_directories(factory PRIVATE ${SOURCES_FOLDER})
