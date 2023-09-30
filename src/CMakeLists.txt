

set(HEADER_LIST
  "${huffman_SOURCE_DIR}/include/huffman/tree.hpp"
  "${huffman_SOURCE_DIR}/include/huffman/huffman.hpp")


add_library(huffman huffman.cpp ${HEADER_LIST})

target_include_directories(huffman PUBLIC ../include)

target_compile_features(huffman PUBLIC cxx_std_11)

# For IDEs
source_group(
  TREE "${PROJECT_SOURCE_DIR}/include"
  PREFIX "Header Files"
  FILES ${HEADER_LIST})
