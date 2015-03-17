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
  TreeNode *sortedArrayToBST(vector<int> &num, int l=-1, int r=-1) {
    if(l == -1)
      l = 0, r = num.size();
    if(l == r)
      return nullptr;
    int m = (l+r)/2;
    TreeNode *root = new TreeNode(num[m]);
    root->left  = sortedArrayToBST(num, l, m);
    root->right = sortedArrayToBST(num, m+1, r);
    return root;
  }
};

int main(){
  auto sol = Solution();
}
