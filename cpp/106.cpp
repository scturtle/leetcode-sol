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
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder,
                      int il=-1, int ir=-1, int pl=-1, int pr=-1) {
    if(pl == -1)
      il = 0, ir = inorder.size(), pl = 0, pr = postorder.size();
    if(il == ir)
      return nullptr;
    TreeNode *root = new TreeNode(postorder[pr-1]);
    int idx = find(inorder.begin()+il, inorder.begin()+ir, postorder[pr-1]) - inorder.begin();
    root->left = buildTree(inorder, postorder, il ,idx, pl, pl+idx-il);
    root->right = buildTree(inorder, postorder, idx+1, ir, pl+idx-il, pr-1);
    return root;
  }
};

int main(){
  auto sol = Solution();
  vector<int> p = {1,2,3};
  vector<int> i = {3,2,1};
  TreeNode *rt = sol.buildTree(p, i);
  cout << rt->val << endl;
  cout << rt->right->val << endl;
  cout << rt->right->right->val << endl;
}
