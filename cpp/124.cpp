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
  pair<int, int> pathSum(TreeNode *root){
    if(root == nullptr)
      return make_pair(INT_MIN, 0);
    auto l = pathSum(root->left), r = pathSum(root->right);
    int ans = max(root->val + max(0, l.second) + max(0, r.second), max(l.first, r.first));
    return make_pair(ans, max(root->val, max(root->val + l.second, root->val + r.second)));
  }
  int maxPathSum(TreeNode *root) {
    if(root == nullptr) return 0;
    return pathSum(root).first;
  }
};

int main(){
  auto sol = Solution();
  TreeNode a(1), b(2), c(3);
  a.left = &b; a.right = &c;
  cout << sol.maxPathSum(&a);
}
