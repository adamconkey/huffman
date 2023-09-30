#include <bitset>
#include <unordered_map>

#include "tree.hpp"


using FrequencyMap = std::unordered_map<char, int>;


class Huffman {

public:

  
  
  Huffman() {}

  std::string encode(std::string text);

    
  

private:

  FrequencyMap computeFrequencies(std::string text);
  
};
