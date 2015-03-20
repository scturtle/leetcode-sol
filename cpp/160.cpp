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
#include <sstream>
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
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int na = 0, nb = 0;
    ListNode *pa = headA, *pb = headB;
    while(pa) ++na, pa = pa->next;
    while(pb) ++nb, pb = pb->next;
    int diff = na - nb;
    pa = headA; pb = headB;
    if(diff > 0)
      while(diff) --diff, pa = pa->next;
    if(diff < 0){
      diff = -diff;
      while(diff) --diff, pb = pb->next;
    }
    while(pa != nullptr && pa != pb)
      pa = pa->next, pb=pb->next;
    return pa;
  }
};

int main(){
  // auto sol = Solution();
}
