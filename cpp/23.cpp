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

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode head(0);
    ListNode *res = &head;
    while(l1 && l2){
      if(l1->val <= l2->val)
        res->next = l1, res = l1, l1 = l1->next;
      else
        res->next = l2, res = l2, l2 = l2->next;
    }
    if(l1) res->next = l1;
    else if(l2) res->next = l2;
    return head.next;
  }

  ListNode *mergeKLists(vector<ListNode *> &lists) {
    if(lists.size() == 0)
      return nullptr;
    vector<ListNode*> *a = &lists, *b = new vector<ListNode*>(), *c;
    while(a->size() > 1){
      for(uint i=0; i+1 < a->size(); i += 2)
        b->push_back(mergeTwoLists(a->at(i), a->at(i+1)));
      if(a->size() % 2 == 1)
        b->push_back(a->back());
      c = a; a = b; b = c;
      b->clear();
    }
    return a->at(0);
  }
};

int main(){
  auto sol = Solution();
  vector<ListNode*> lists{new ListNode(2), nullptr, new ListNode(-1)};
  auto res = sol.mergeKLists(lists);
  while(res){
    cout << res->val << " -> ";
    res = res->next;
  }
}
