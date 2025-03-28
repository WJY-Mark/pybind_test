cmake_minimum_required(VERSION 3.1) 
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
project(test_pybind)
# find_package( OpenCV REQUIRED)
# include_directories(${OpenCV_INCLUDE_DIRS})
# message("MY_VARIABLE: ${pybind11_DIR}")
add_subdirectory(pybind11)
SET(SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
        )
pybind11_add_module(test_pybind ${SOURCES})
# target_link_libraries( test_pybind PRIVATE ${OpenCV_LIBS} )