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

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  TreeNode *sortedListToBST(ListNode *head) {
    if(head == nullptr)
      return nullptr;
    ListNode *pp = nullptr, *p, *p2;
    p = p2 = head;
    while(p2 && p2->next)
      pp = p, p = p->next, p2 = p2->next->next;
    TreeNode *root = new TreeNode(p->val);
    if(pp != nullptr){
      p2 = pp->next; pp->next = nullptr;
      root->left = sortedListToBST(head);
      pp->next = p2;
    }
    root->right = sortedListToBST(p->next);
    return root;
  }
};

int main(){
  auto sol = Solution();
}
