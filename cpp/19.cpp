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
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *f = nullptr, *t = head;
    for(int i=0; i<n; ++i)
      t = t->next;
    while(t)
      f = f ? f->next : head, t = t->next;
    if(f){
      f->next = f->next->next;
      return head;
    } else
      return head->next;
  }
};

int main(){
  auto sol = Solution();
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  sol.removeNthFromEnd(head, 1);
}
