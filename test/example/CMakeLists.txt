cmake_minimum_required(VERSION 3.12)
project(MyModule)

# Find pybind11
find_package(pybind11 REQUIRED)

# Find Protobuf
find_package(Protobuf REQUIRED)

# Include directories
include_directories(${Protobuf_INCLUDE_DIRS})

# add_library(knot knot.cpp)

# Set the source files
set(SOURCES main.cpp message.pb.cc)

message("Linking ${CMAKE_CURRENT_SOURCE_DIR}/knot lib")

link_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Create the pybind11 module
pybind11_add_module(my_module ${SOURCES})

# Link Protobuf
target_link_libraries(my_module PRIVATE ${Protobuf_LIBRARIES} knot)