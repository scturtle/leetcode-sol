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
  ListNode *rotateRight(ListNode *head, int k) {
    if(head == nullptr) return nullptr;
    ListNode *h = head, *p;
    int n = 0;
    while(h != nullptr) ++n, p = h, h = h->next;
    k %= n;
    if(k == 0) return head;
    p->next = h = head;
    for(int i=0; i<n-k-1; i++)
      h = h->next;
    p = h->next;
    h->next = nullptr;
    return p;
  }
};


int main(){
  auto sol = Solution();
  ListNode *one = new ListNode(1);
  ListNode *two = new ListNode(2);
  one->next = two;
  ListNode *h = sol.rotateRight(one, 1);
  while(h){
    cout << h->val << endl;
    h = h->next;
  }
}
