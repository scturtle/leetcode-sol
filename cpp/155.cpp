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

class MinStack {
  vector<int> stack;
  vector<int> mins;
public:
  void push(int x) {
    if(mins.empty() || x <= mins.back())
      mins.push_back(x);
    stack.push_back(x);
  }

  void pop() {
    if(stack.back() == mins.back())
      mins.pop_back();
    stack.pop_back();
  }

  int top() {
    return stack.back();
  }

  int getMin() {
    return mins.back();
  }
};

int main(){
  // auto sol = Solution();
}
