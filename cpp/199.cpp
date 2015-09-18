#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  vector<int> rightSideView(TreeNode *root) {
    if (root == nullptr)
      return {};
    vector<int> res{root->val};
    vector<int> l = rightSideView(root->left), r = rightSideView(root->right);
    copy(r.begin(), r.end(), back_inserter(res));
    if(l.size() > r.size())
      copy(l.begin() + r.size(), l.end(), back_inserter(res));
    return res;
  }
};
