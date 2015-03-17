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
  vector<TreeNode *> generateTrees(int n, int idx=1) {
    if(n == 0)
      return vector<TreeNode*>{nullptr};
    if(n == 1)
      return vector<TreeNode*>{new TreeNode(idx)};
    vector<TreeNode*> ans;
    for(int l=0; l<n; l++){
      auto lts = generateTrees(l, idx), rts = generateTrees(n-1-l, idx+l+1);
      for(auto lt : lts)
        for(auto rt : rts){
          TreeNode *t = new TreeNode(idx+l);
          t->left = lt; t->right = rt;
          ans.push_back(t);
        }
    }
    return ans;
  }
};

int main(){
  auto sol = Solution();
}
