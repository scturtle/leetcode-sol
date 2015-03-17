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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
    vector<vector<int> > ans;
    if(root == nullptr)
      return ans;
    vector<TreeNode*> v1, v2;
    v1.push_back(root);
    vector<TreeNode*> *a = &v1, *b = &v2, *c;
    while(a->size() != 0){
      ans.push_back(vector<int>());
      for(TreeNode *t : *a){
        ans.back().push_back(t->val);
        if(t->left != nullptr)
          b->push_back(t->left);
        if(t->right != nullptr)
          b->push_back(t->right);
      }
      c = a; a = b; b = c;
      b->clear();
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};

int main(){
  auto sol = Solution();
}
