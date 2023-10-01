#include <string>
#include <unordered_map>

#include "tree.hpp"


using FrequencyMap = std::unordered_map<char, int>;
using TreeNodePtr = std::shared_ptr<TreeNode>;


class Huffman {

public:
  
    Huffman() {}
    
    std::string encode(std::string text);
    
    FrequencyMap computeFrequencies(std::string text);

    TreeNodePtr createEncodingTree(FrequencyMap freqs);
    
};
