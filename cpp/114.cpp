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
  TreeNode *_flatten(TreeNode *root, TreeNode *end){
    if(root == nullptr)
      return end;
    root->right = _flatten(root->left, _flatten(root->right, end));
    root->left = nullptr;
    return root;
  }
  void flatten(TreeNode *root) {
    _flatten(root, nullptr);
  }
};

int main(){
  auto sol = Solution();
}
