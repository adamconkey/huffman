cmake_minimum_required(VERSION 3.14)
project(huffman)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)


include(CTest)
include(FetchContent)


add_subdirectory(src)   # Library code
add_subdirectory(apps)  # Executable code
if (BUILD_TESTING)
  add_subdirectory(test)
endif()
