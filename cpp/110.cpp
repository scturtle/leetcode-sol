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
  pair<bool, int> _isBalanced(TreeNode *root){
    if(root == nullptr)
      return make_pair(true, 0);
    pair<bool, int> l = _isBalanced(root->left);
    pair<bool, int> r = _isBalanced(root->right);
    return make_pair(l.first && r.first && abs(l.second - r.second) <= 1,
                     1 + max(l.second, r.second));
  }
  bool isBalanced(TreeNode *root) {
    return _isBalanced(root).first;
  }
};

int main(){
  auto sol = Solution();
}
