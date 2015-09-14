#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  void dfs(TreeNode* root, TreeNode* p, TreeNode* q,
           vector<TreeNode*> &cur, vector<vector<TreeNode*>> &res){
    cur.push_back(root);
    if(root == p || root == q)
      res.push_back(vector<TreeNode*>(cur.begin(), cur.end()));
    if(root->left) dfs(root->left, p, q, cur, res);
    if(root->right) dfs(root->right, p, q, cur, res);
    cur.pop_back();
  }
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode*> cur;
    vector<vector<TreeNode*>> res;
    dfs(root, p, q, cur, res);
    TreeNode* ans;
    int i = 0;
    while(res[0][i] == res[1][i]){
      ans = res[0][i]; ++i;
    }
    return ans;
  }
};
