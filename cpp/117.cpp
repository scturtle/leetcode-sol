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

struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
  void connect(TreeLinkNode *root) {
    if(root == nullptr)
      return;
    TreeLinkNode *p = root->next, *nxt = nullptr;
    while(p){
      if(p->left) {nxt = p->left; break;}
      if(p->right) {nxt = p->right; break;}
      p = p->next;
    }
    if(root->right){
      root->right->next = nxt;
      nxt = root->right;
    }
    if(root->left)
      root->left->next = nxt;
    connect(root->right);
    connect(root->left);
  }
};

int main(){
  auto sol = Solution();
  TreeLinkNode a(1), b(2), c(3), d(4), e(5), f(6), g(7), h(8);
  a.left = &b; a.right = &c;
  b.left = &d; b.right = &e;
  c.right = &f;
  d.left = &g;
  f.right = &h;
  sol.connect(&a);
}
