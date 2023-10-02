#include <iostream>
#include "huffman/huffman.hpp"


int main() {

  Huffman huffman;
  std::string text("This is just a test");
  std::string code = huffman.encode(text);

  std::cout << "TEXT: " << text << std::endl;
  std::cout << "CODE: " << code << std::endl;
  
  return 0;
}
