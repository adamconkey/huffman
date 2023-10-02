#include <queue>
#include <iostream>

#include "huffman/huffman.hpp"


using namespace std;


string Huffman::encode(string text) {
    string code;
    
    // Compute character frequencies in string
    FrequencyMap freqs = computeFrequencies(text);

    // cout << "FREQ" << endl;
    // for (auto & e : freqs)
    // 	cout << e.first << '\t' << e.second << endl;

    
    // Create binary tree according to character frequencies
    TreeNodePtr encoding_tree = createEncodingTree(freqs);

    // Create codes for each character based on encoding tree
    CodeMap code_map = createCodeMap(encoding_tree);

    // cout << "\nCODE" << endl;
    // for (auto & e : code_map)
    // 	cout << e.first << '\t' << e.second << endl;

    // Endode the string text using the code map
    for (char c : text)
	code += code_map[c];
    
    return code;
}


FrequencyMap Huffman::computeFrequencies(string text) {
    FrequencyMap freqs;
    for (char c : text)
	freqs[c]++;
    return freqs;
}


TreeNodePtr Huffman::createEncodingTree(FrequencyMap freqs) {

    // TODO should be better way to handle this base case
    if (freqs.empty()) {
	return make_shared<TreeNode>();
    }

    // Create min priority queue with custom comparator (lambda) to 
    // sort based on frequency stored on nodes
    auto compare_freq = [](TreeNodePtr t1, TreeNodePtr t2) { return t1->freq > t2->freq; };
    priority_queue<TreeNodePtr, vector<TreeNodePtr>, decltype(compare_freq)> pq(compare_freq);

    // Create leaf nodes for each char/freq and add to PQ
    for (auto &entry : freqs)
	pq.push(make_shared<TreeNode>(entry.second, entry.first));
    
    // Process nodes until there's only one left, at which point that's the root to return
    const int num_chars = freqs.size();
    for (int i = 0; i < num_chars - 1; i++) {
	TreeNode new_node;
	// Add the lowest-freq node as left child
	new_node.left = pq.top();
	new_node.freq = new_node.left->freq;
	pq.pop();
	// Add the next lowest-freq node as right child (if it exists)
	if (!pq.empty()) {
	    new_node.right = pq.top();
	    new_node.freq += new_node.right->freq;
	    pq.pop();
	}
	// Insert the newly created node to the PQ
	pq.push(make_shared<TreeNode>(new_node));
    }

    return pq.top();
}


CodeMap Huffman::createCodeMap(TreeNodePtr root) {
    CodeMap code_map;
    std::string code("");

    traverseTreeDfs(root, code, code_map);
    
    return code_map;
}


void Huffman::traverseTreeDfs(TreeNodePtr root, string& code, CodeMap& code_map) {
    if (root->left == nullptr && root->right == nullptr) {
	// We've hit a leaf, add the char to the code map
	code_map[root->character] = code;
    } else {
	// Recurse on the left and right sub-trees to continue search for leaf nodes
	if (root->left != nullptr) {
	    string new_code (code + "0");
	    traverseTreeDfs(root->left, new_code, code_map);
	}
	if (root->right != nullptr) {
	    string new_code (code + "1");
	    traverseTreeDfs(root->right, new_code, code_map);
	}
    }
}


