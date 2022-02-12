cmake_minimum_required(VERSION 3.5)

project(mind_map LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC_LIST
    main.cpp
    src/json_manipulator.cpp
    src/themes.cpp            )

set(HEADERS
    include/shortenings.hpp
    include/json_manipulator.hpp
    include/themes.hpp           )

#add_executable(mind_map main.cpp)
#add_subdirectory(src)
#add_subdirectory(include)
add_executable(${PROJECT_NAME} ${SRC_LIST} ${HEADERS})
target_include_directories(${PROJECT_NAME} PUBLIC include)
