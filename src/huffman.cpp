
#include "huffman/huffman.hpp"


std::string Huffman::encode(std::string text) {
    std::string code;
    
    // Compute character frequencies in string
    FrequencyMap freqs = computeFrequencies(text);

    // Create binary tree according to character frequencies
    TreeNode* encoding_tree = createEncodingTree(freqs);
    
    
    
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


TreeNode* Huffman::createEncodingTree(FrequencyMap freqs) {
    TreeNode* root;

    // TODO create leaf nodes for each char/freq

    // TODO add all leaf nodes to priority queue keyed on the node's freq

    // TODO build tree pulling elements from PQ and adding new node with those as children

    // TODO continue until PQ is empty, return root storing encoding tree
    
    return root;
}
