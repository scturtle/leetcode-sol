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
  void reorderList(ListNode *head) {
    deque<ListNode*> q;
    while(head){
      q.push_back(head);
      head = head->next;
    }
    ListNode h(0), *p = &h;
    while(!q.empty()){
      p->next = q.front(); q.pop_front();
      p = p->next;
      if(!q.empty()){
        p->next = q.back(); q.pop_back();
        p = p->next;
      }
    }
    p->next = nullptr;
  }
};

int main(){
  auto sol = Solution();
  ListNode a(1), b(2), c(3);
  a.next = &b; b.next = &c;
  sol.reorderList(&a);
  cout << a.val << a.next->val << a.next->next->val << endl;
}
