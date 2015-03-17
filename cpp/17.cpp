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
  vector<string> letterCombinations(string digits) {
    vector<string> ans = {""};
    if(digits.length() == 0){
      ans.pop_back(); return ans;
    }
    vector<string> m  = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    for(auto& d : digits){
      vector<string> cur;
      for(auto& c : m[d-'2'])
        for(auto& s : ans)
          cur.push_back(s+c);
      ans = cur;
    }
    return ans;
  }
};

int main(){
  auto sol = Solution();
  for(auto& s : sol.letterCombinations("23"))
    cout << s << endl;
}
