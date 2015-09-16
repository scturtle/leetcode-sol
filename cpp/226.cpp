struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode* invertTree(TreeNode* root) {
    if(root == nullptr)
      return nullptr;
    auto t = new TreeNode(root->val);
    t->left = invertTree(root->right);
    t->right = invertTree(root->left);
    return t;
  }
};
