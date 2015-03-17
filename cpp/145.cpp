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
  vector<int> postorderTraversal(TreeNode *root, vector<int> *v=nullptr) {
    if(v == nullptr)
      v = new vector<int>();
    if(root == nullptr)
      return *v;
    preorderTraversal(root->left, v);
    preorderTraversal(root->right, v);
    v->push_back(root->val);
    return *v;
  }
};

int main(){
  auto sol = Solution();
}
