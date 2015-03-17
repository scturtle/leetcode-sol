#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <utility>
#include <map>
#include <string>
#include <unordered_map>
#include <climits>
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
  string longestCommonPrefix(vector<string> &strs) {
    if(strs.empty())
      return "";
    int r = strs[0].length();
    for(const auto& s : strs){
      int i=0;
      while(i < s.length() && i < r && s[i] == strs[0][i])
        ++i;
      r = i;
    }
    return strs[0].substr(0, r);
  }
};

int main(){
  auto sol = Solution();
  vector<string> v = {"aaa", "aab", "abb"};
  cout << sol.longestCommonPrefix(v);
}
