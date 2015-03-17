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

struct UndirectedGraphNode {
  int label;
  vector<UndirectedGraphNode *> neighbors;
  UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
  UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node,
    unordered_map<UndirectedGraphNode*,UndirectedGraphNode*> *memo=nullptr) {
    if(node == nullptr)
      return nullptr;
    if(memo == nullptr)
      memo = new unordered_map<UndirectedGraphNode*,UndirectedGraphNode*>();
    if(memo->find(node) != memo->end())
      return (*memo)[node];
    UndirectedGraphNode *newnode = new UndirectedGraphNode(node->label);
    (*memo)[node] = newnode;
    for(auto neighbor : node->neighbors)
      newnode->neighbors.push_back(cloneGraph(neighbor, memo));
    return newnode;
  }
};

int main(){
  auto sol = Solution();
}
