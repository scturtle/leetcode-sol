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
  vector<vector<int> > pathSum(TreeNode *root, int sum) {
    vector<vector<int> > ans;
    if(root == nullptr)
      return ans;
    if(root->left == nullptr && root->right == nullptr){
      if(root->val == sum)
        ans.push_back({root->val});
      return ans;
    }
    auto ls = pathSum(root->left, sum - root->val);
    auto rs = pathSum(root->right, sum - root->val);
    for(auto &l : ls)
      l.insert(l.begin(), root->val), ans.push_back(l);
    for(auto &r : rs)
      r.insert(r.begin(), root->val), ans.push_back(r);
    return ans;
  }
};

int main(){
  auto sol = Solution();
}
