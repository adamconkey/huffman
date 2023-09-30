#include <iostream>

#include "huffman.hpp"


std::string Huffman::encode(std::string text) {
  std::string code;

  // Compute character frequencies in string
  FrequencyMap freqs = computeFrequencies(text);

  for (const auto &p : freqs) {
    std::cout << p.first << '\t' << p.second << '\n';
  }

  
  
  // TODO create tree according to frequencies

  // TODO set codes in map for each char based on tree traversal

  // TODO encode the string text using the code map

  return code;
}


FrequencyMap Huffman::computeFrequencies(std::string text) {
  FrequencyMap freqs;

  for (char c : text)
    freqs[c]++;

  
  return freqs;
}



// TODO want to setup a cmake file and basic unit tests for computeFrequencies




int main() {

  Huffman huffman;
  std::string text("This is just a test");
  huffman.encode(text);

  return 0;
}