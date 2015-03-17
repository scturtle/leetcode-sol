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
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode h(0);
    h.next = head;
    ListNode *p = &h;
    while(p->next && p->next->next){
      if(p->next->val == p->next->next->val){
        int v = p->next->val;
        while(p->next && p->next->val == v)
          p->next = p->next->next;
      }
      else
        p = p->next;
    }
    return h.next;
  }
};

int main(){
  auto sol = Solution();
}
