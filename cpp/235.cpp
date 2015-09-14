#include<vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    vector<TreeNode*> path = {root};
    TreeNode* t = root;
    while(t != p){
      if(p->val < t->val)
        t = t->left;
      else
        t = t->right;
      path.push_back(t);
    }
    vector<TreeNode*> path2 = {root};
    t = root;
    while(t != q){
      if(q->val < t->val)
        t = t->left;
      else
        t = t->right;
      path2.push_back(t);
    }
    size_t i = 0;
    while(i < path.size() && i < path2.size()){
      if(path[i] == path2[i])
        t = path[i];
      else
        break;
      ++i;
    }
    return t;
  }
};
