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

class Solution {
public:
  bool isValid(string s) {
    vector<char> stack;
    for(auto& c : s){
      if(c == '(' || c == '{' || c == '[')
        stack.push_back(c);
      else if(c == ')' && !stack.empty() && stack.back() == '(')
        stack.pop_back();
      else if(c == '}' && !stack.empty() && stack.back() == '{')
        stack.pop_back();
      else if(c == ']' && !stack.empty() && stack.back() == '[')
        stack.pop_back();
      else
        return false;
    }
    return stack.empty();
  }
};

int main(){
  auto sol = Solution();
}
