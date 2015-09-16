struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  int countNodes(TreeNode* root) {
    int lc =0, rc = 0;
    for(auto t = root; t; t = t->left) ++lc;
    for(auto t = root; t; t = t->right) ++rc;
    if(lc == rc)
      return pow(2, lc) - 1;
    else
      return 1 + countNodes(root->left) + countNodes(root->right);
  }
};
