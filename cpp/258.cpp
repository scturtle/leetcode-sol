#include<vector>
#include<string>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  vector<string> binaryTreePaths(TreeNode *root) {
    if(root == nullptr)
      return {};
    if(root->left == nullptr && root->right == nullptr)
      return {to_string(root->val)};
    vector<string> res;
    for(string& p : binaryTreePaths(root->left))
      res.push_back(to_string(root->val)+"->"+p);
    for(string& p : binaryTreePaths(root->right))
      res.push_back(to_string(root->val)+"->"+p);
    return res;
  }
};
