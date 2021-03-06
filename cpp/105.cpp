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
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder,
                      int pl=-1, int pr=-1, int il=-1, int ir=-1) {
    if(pl == -1)
      pl = 0, pr = preorder.size(), il = 0, ir = inorder.size();
    if(pl == pr)
      return nullptr;
    TreeNode *root = new TreeNode(preorder[pl]);
    int idx = find(inorder.begin()+il, inorder.begin()+ir, preorder[pl]) - inorder.begin();
    root->left = buildTree(preorder, inorder, pl+1, pl+1+idx-il, il ,idx);
    root->right = buildTree(preorder, inorder, pl+1+idx-il, pr, idx+1, ir);
    return root;
  }
};

int main(){
  auto sol = Solution();
  vector<int> p = {1,2,3};
  vector<int> i = {1,2,3};
  TreeNode *rt = sol.buildTree(p, i);
  cout << rt->val << endl;
  cout << rt->right->val << endl;
  cout << rt->right->right->val << endl;
}
