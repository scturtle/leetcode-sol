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
  ListNode *partition(ListNode *head, int x) {
    if(head == nullptr)
      return nullptr;
    ListNode h(0);
    ListNode *p = head;
    vector<ListNode*> v;
    while(p){if(p->val < x) v.push_back(p); p = p->next;}
    p = head;
    while(p){if(p->val >= x) v.push_back(p); p = p->next;}
    p = &h;
    for(ListNode *t : v)
      p->next = t, p = t;
    p->next = nullptr;
    return h.next;
  }
};

int main(){
  auto sol = Solution();
}
