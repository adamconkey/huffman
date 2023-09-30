cmake_minimum_required(VERSION 3.10)
project(huffman)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


add_subdirectory(src)   # Library code
add_subdirectory(apps)  # Executable code

