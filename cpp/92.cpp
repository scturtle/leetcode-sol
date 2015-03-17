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
  ListNode *reverseBetween(ListNode *head, int m, int n) {
    ListNode h(0);
    h.next = head;
    ListNode *p = &h, *t;
    vector<ListNode*> v;
    for(int i=0; i<m-1; i++)
      p = p->next;
    for(int i=0; i<n-m+1; i++)
      v.push_back(p->next), p->next = p->next->next;
    t = p->next;
    while(!v.empty()){
      p->next = v.back();
      p = v.back();
      v.pop_back();
    }
    p->next = t;
    return h.next;
  }
};

int main(){
  auto sol = Solution();
  ListNode a(1), b(2);
  a.next = &b;
  ListNode *p = sol.reverseBetween(&a, 1, 2);
  while(p)
    cout << p->val << endl, p = p->next;
}
