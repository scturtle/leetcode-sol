#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <utility>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <climits>
#include <numeric>
using namespace std;

template<typename T>
void prints(vector<T> &v){
  cout << "[";
  for(uint i=0; i<v.size()-1; ++i)
    cout << v[i] << ", ";
  if(v.size()) cout << v[v.size()-1];
  cout << "]\n";
}

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  void preorder(TreeNode *root, vector<int> &ans){
    if(root == nullptr)
      return;
    preorder(root->left, ans);
    ans.push_back(root->val);
    preorder(root->right, ans);
  }
  void setvalue(TreeNode *root, vector<int> &vals){
    if(root == nullptr)
      return;
    setvalue(root->left, vals);
    root->val = vals.back();
    vals.pop_back();
    setvalue(root->right, vals);
  }
  void recoverTree(TreeNode *root) {
    vector<int> vals;
    preorder(root, vals);
    sort(begin(vals), end(vals));
    reverse(begin(vals), end(vals));
    setvalue(root, vals);
  }
};

int main(){
  auto sol = Solution();
}
