#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <utility>
#include <map>
#include <set>
#include <string>
#include <deque>
#include <unordered_map>
#include <unordered_set>
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
  pair<int, int> _sumNumbers(TreeNode *root){
    if(root == nullptr)
      return make_pair(0, 0);
    if(root->left == nullptr && root->right == nullptr)
      return make_pair(root->val, 10);
    auto l = _sumNumbers(root->left);
    auto r = _sumNumbers(root->right);
    return make_pair((l.second + r.second) * root->val + l.first + r.first,
                     (l.second + r.second) * 10);

  }
  int sumNumbers(TreeNode *root) {
    return _sumNumbers(root).first;
  }
};

int main(){
  auto sol = Solution();
}
