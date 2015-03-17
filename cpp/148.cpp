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
  ListNode *sortList(ListNode *head) {
    if(head == nullptr || head->next == nullptr)
      return head;
    ListNode h(0), *a, *b, *p;
    h.next = head;
    a = b = &h;
    while(b->next && b->next->next){
      a = a->next; b = b->next->next;
    }
    b = a->next;
    a->next = nullptr;
    a = head;
    a = sortList(a); b = sortList(b);
    h.next = nullptr; p = &h;
    while(a && b){
      if(a->val <= b->val){
        p->next = a; p = a; a = a->next;
      } else {
        p->next = b; p = b; b = b->next;
      }
    }
    p->next = a ? a : b;
    return h.next;
  }
};

int main(){
  auto sol = Solution();
  ListNode a(3), b(2), c(1);
  a.next = &b; b.next = &c;
  auto p = sol.sortList(&a);
  while(p)
    cout << p->val << endl, p = p->next;
}
