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

class Solution {
public:
  int evalRPN(vector<string> &tokens) {
    vector<int> stack;
    for(auto &s : tokens){
      if(s == "+"){
        int a = stack.back(); stack.pop_back();
        int b = stack.back(); stack.pop_back();
        stack.push_back(b + a);
      } else if(s == "-"){
        int a = stack.back(); stack.pop_back();
        int b = stack.back(); stack.pop_back();
        stack.push_back(b - a);
      } else if(s == "*"){
        int a = stack.back(); stack.pop_back();
        int b = stack.back(); stack.pop_back();
        stack.push_back(b * a);
      } else if(s == "/"){
        int a = stack.back(); stack.pop_back();
        int b = stack.back(); stack.pop_back();
        stack.push_back(b / a);
      } else {
        stack.push_back(atoi(s.c_str()));
      }
    }
    return stack.back();
  }
};

int main(){
  auto sol = Solution();
}
