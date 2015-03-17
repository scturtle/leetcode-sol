#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <unordered_map>
using namespace std;

template<typename T>
void prints(vector<T> &v){
  cout << "[";
  for(uint i=0; i<v.size()-1; ++i)
    cout << v[i] << ", ";
  if(v.size()) cout << v[v.size()-1];
  cout << "]\n";
}

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2, int add=0){
    if(!l1 && !l2){
      return add ? new ListNode(add) : nullptr;
    }
    else{
      int val = (l1?l1->val:0) + (l2?l2->val:0) + add;
      int nxt_add = 0;
      if(val >= 10)
        val -= 10, ++nxt_add;
      auto t = new ListNode(val);
      t->next = addTwoNumbers(l1?l1->next:nullptr,
                               l2?l2->next:nullptr,
                               nxt_add);
      return t;
    }
  }
};

int main(){
  auto sol = Solution();
  auto l1 = new ListNode(0);
  auto l2 = new ListNode(0);
  auto res = sol.addTwoNumbers(l1, l2);
}
