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
  bool hasPathSum(TreeNode *root, int sum) {
    if(root == nullptr)
      return false;
    if(root->left == nullptr && root->right == nullptr)
      return root->val == sum;
    if(root->left && hasPathSum(root->left, sum - root->val))
      return true;
    if(root->right && hasPathSum(root->right, sum - root->val))
      return true;
    return false;
  }
};

int main(){
  auto sol = Solution();
}
