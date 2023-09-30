#include "huffman/huffman.hpp"


int main() {

  Huffman huffman;
  std::string text("This is just a test");
  huffman.encode(text);

  return 0;
}
