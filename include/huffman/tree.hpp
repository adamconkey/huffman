


class TreeNode {

public:

  int freq;
  TreeNode* left;
  TreeNode* right;
  
  TreeNode() {}

  TreeNode(int freq) : freq(freq) {}

  TreeNode(int freq, TreeNode* left, TreeNode* right) : freq(freq), left(left), right(right) {}
  
};
