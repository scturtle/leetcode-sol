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

struct RandomListNode {
  int label;
  RandomListNode *next, *random;
  RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
  RandomListNode *copyRandomList(RandomListNode *head,
      unordered_map<RandomListNode*,RandomListNode*> *memo=nullptr) {
    if(head == nullptr) return head;
    if(memo == nullptr)
      memo = new unordered_map<RandomListNode*, RandomListNode*>();
    if(memo->find(head) != memo->end())
      return (*memo)[head];
    RandomListNode *newhead = new RandomListNode(head->label);
    (*memo)[head] = newhead;
    newhead->next = copyRandomList(head->next, memo);
    newhead->random = copyRandomList(head->random, memo);
    return newhead;
  }
};

int main(){
  auto sol = Solution();
}
