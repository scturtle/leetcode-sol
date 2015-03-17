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
  ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode h(0);
    h.next = head;
    ListNode *a = &h, *b = &h, *c;
    vector<ListNode*> v;
    while(a){
      b = a;
      for(int i=0; i<k && b->next; ++i)
        v.push_back(b->next), b = b->next;
      if(v.size() < k) // not enough
        break;
      c = b->next;
      // reverse k listnodes in v
      for(int i=0; i<k; i++){
        ListNode *t = v.back(); v.pop_back();
        a->next = t;
        a = t;
      }
      a->next = c;
    }
    return h.next;
  }
};

int main(){
  auto sol = Solution();
  ListNode a(1), b(2), c(3), d(4), e(5);
  a.next = &b;
  // b.next = &c;
  // c.next = &d;
  // d.next = &e;
  ListNode *res = sol.reverseKGroup(&a, 2);
  while(res){
    cout << res->val << "->";
    res = res->next;
  }
}
