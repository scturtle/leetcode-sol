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
  ListNode *swapPairs(ListNode *head) {
    ListNode h(-1);
    h.next = head;
    ListNode *a = &h, *b, *c;
    while(a && a->next && a->next->next){
      b = a->next;
      c = b->next;
      a->next = c;
      b->next = c->next;
      c->next = b;
      a = b;
    }
    return h.next;
  }
};

int main(){
  auto sol = Solution();
}
