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
#include <sstream>
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

class BSTIterator {
  TreeNode *cur;
  vector<TreeNode*> parents;
public:
  BSTIterator(TreeNode *root) {
    cur = root;
    while(cur && cur->left != nullptr){
      parents.push_back(cur);
      cur = cur->left;
    }
  }

  /** @return whether we have a next smallest number */
  bool hasNext() {
    return cur != nullptr;
  }

  /** @return the next smallest number */
  int next() {
    int v = cur->val;
    if(cur->right != nullptr){
      cur = cur->right;
      while(cur->left != nullptr){
        parents.push_back(cur);
        cur = cur->left;
      }
    } else {
      if(parents.empty())
        cur = nullptr;
      else {
        cur = parents.back();
        parents.pop_back();
      }
    }
    return v;
  }
};

int main(){
  // auto sol = Solution();
  TreeNode a(1), b(2), c(3);
  b.left = &a; b.right = &c;
  BSTIterator i = BSTIterator(nullptr);
  while (i.hasNext()) cout << i.next();
  return 0;
}
