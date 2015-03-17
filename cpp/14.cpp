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
    int n = strs.size();
    if(!n) return "";
    string ans(strs[0]);
    for(const auto& s : strs){
      auto a = ans.begin();
      auto b = s.begin();
      while(a != ans.end() && b != s.end() && *a == *b) ++a, ++b;
      ans = ans.substr(0, a - ans.begin());
    }
    return ans;
  }
};

int main(){
  auto sol = Solution();
  vector<string> v = {""};
  cout << sol.longestCommonPrefix(v);
}
