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

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *insertionSortList(ListNode *head) {
    ListNode h(0), *t, *p;
    while(head){
      t = head; head = head->next;
      p = &h;
      while(p->next && t->val > p->next->val)
        p = p->next;
      t->next = p->next;
      p->next = t;
    }
    return h.next;
  }
};

int main(){
  auto sol = Solution();
  ListNode a(3), b(2), c(1);
  a.next = &b; b.next = &c;
  auto p = sol.insertionSortList(&a);
  while(p)
    cout << p->val << endl, p = p->next;
}
