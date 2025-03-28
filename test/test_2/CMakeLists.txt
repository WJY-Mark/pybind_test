
cmake_minimum_required(VERSION 3.12)  # Specify the minimum CMake version
project(test_pybind)                   # Name of your project

# Find pybind11 package
find_package(pybind11 REQUIRED)

# Create a shared library for the Python modulecmakecmake
# set(pybind11_DIR "/home/wangjunyang/.local/lib/python3.8/site-packages/pybind11/share/cmake/pybind11")
pybind11_add_module(test_pybind main.cpp)  # Replace src/main.cpp with your source file path

# Optionally, you can set C++ standard
set_target_properties(test_pybind PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED YES
)