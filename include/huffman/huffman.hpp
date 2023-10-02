#include <string>
#include <unordered_map>

#include "tree.hpp"


using FrequencyMap = std::unordered_map<char, int>;
using CodeMap = std::unordered_map<char, std::string>;
using TreeNodePtr = std::shared_ptr<TreeNode>;


class Huffman {

public:
  
    Huffman() {}
    
    std::string encode(std::string text);
    
    FrequencyMap computeFrequencies(std::string text);

    TreeNodePtr createEncodingTree(FrequencyMap freqs);

    CodeMap createCodeMap(TreeNodePtr root);

    void traverseTreeDfs(TreeNodePtr root, std::string& code, CodeMap& code_map);
    
};
