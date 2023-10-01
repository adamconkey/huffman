#include <memory>


struct TreeNode {    
    int freq;
    char character;
    // TODO these should really be unique_ptr, was having trouble with them though
    std::shared_ptr<TreeNode> left;
    std::shared_ptr<TreeNode> right;

    // Taking the compiler-generated operators (requires C++20)
    auto operator<=>(const TreeNode&) const = default;
    
    TreeNode() : freq(0), character('\0'), left(nullptr), right(nullptr) {}
    // // Take default copy and move constructors
    // TreeNode(TreeNode const &) = default;
    // TreeNode(TreeNode&&) = default;
        
    TreeNode(int freq) : freq(freq), character('\0'), left(nullptr), right(nullptr) {}
    
    TreeNode(int freq, char character) : freq(freq), character(character), left(nullptr), right(nullptr) {}
    
    
};
