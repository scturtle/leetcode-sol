#include<utility>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  pair<int, int> kth(TreeNode* root, int k){
    int lcnt = 0, rcnt = 0, lval, rval;
    if(root->left){
      auto p = kth(root->left, k);
      lcnt = p.first; lval = p.second;
    }
    if(root->right){
      auto p = kth(root->right, k-lcnt-1);
      rcnt = p.first; rval = p.second;
    }
    int total = lcnt + 1 + rcnt;
    if(k <= lcnt) return {total, lval};
    else if (k == lcnt+1) return {total, root->val};
    else return {total, rval};
  }
public:
  int kthSmallest(TreeNode* root, int k) {
    return kth(root, k).second;
  }
};
