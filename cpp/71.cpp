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
  string simplifyPath(string path) {
    vector<string> stack;
    int i, last = 0;
    for(i=1; i<path.length(); i++)
      if(path[i] == '/')
        stack.push_back(path.substr(last+1, i-last-1)), last = i;
    if(last+1 != i)
      stack.push_back(path.substr(last+1, i-last-1));
    vector<string> stack2;
    for(auto &s : stack)
      if(s == "" || s == ".")
        continue;
      else if(s == ".."){
        if(stack2.size()) stack2.pop_back();
      }else
        stack2.push_back(s);
    if(stack2.size() == 0)
      return "/";
    string ans;
    for(auto &s : stack2)
      ans += "/" + s;
    return ans;
  }
};

int main(){
  auto sol = Solution();
  cout << sol.simplifyPath("/a/b//cc/d/e");
}
