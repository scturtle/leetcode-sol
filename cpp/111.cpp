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
  int minDepth(TreeNode *root) {
    if(root == nullptr)
      return 0;
    if(root->left == nullptr && root->right == nullptr)
      return 1;
    if(root->left == nullptr)
      return 1+minDepth(root->right);
    if(root->right == nullptr)
      return 1+minDepth(root->left);
    return 1+min(minDepth(root->left), minDepth(root->right));
  }
};

int main(){
  auto sol = Solution();
}
