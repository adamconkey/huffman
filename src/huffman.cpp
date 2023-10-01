#include <queue>
#include <iostream>

#include "huffman/huffman.hpp"


using namespace std;


string Huffman::encode(string text) {
    string code;
    
    // Compute character frequencies in string
    FrequencyMap freqs = computeFrequencies(text);

    // Create binary tree according to character frequencies
    TreeNodePtr encoding_tree = createEncodingTree(freqs);
    
    
    
    // TODO set codes in map for each char based on tree traversal
    
    // TODO encode the string text using the code map
    
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
    auto compare_freq = [](TreeNodePtr t1, TreeNodePtr t2) { return t1->freq < t2->freq; };
    priority_queue<TreeNodePtr, vector<TreeNodePtr>, decltype(compare_freq)> pq(compare_freq);

    // Create leaf nodes for each char/freq and add to PQ
    for (auto &entry : freqs)
	pq.push(make_shared<TreeNode>(entry.second, entry.first));
    
    // Process nodes until there's only one left, at which point that's the root to return
    for (int i = 0; i < pq.size() - 1; i++) {
	TreeNode new_node;
	// Add the lowest-freq node as left child
	new_node.left = pq.top();
	cout << new_node.left->character << endl;
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
