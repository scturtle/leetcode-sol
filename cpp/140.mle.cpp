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
  vector<string> wordBreak(string s, unordered_set<string> &dict) {
    int n = s.length();
    vector<vector<string> > ans(n+1);
    ans[0].push_back({""});
    for(int j=1; j<=n; j++)
      for(int i=0; i<j; i++){
        string t = s.substr(i, j-i);
        if(dict.find(t) != dict.end())
          for(auto v : ans[i])
            ans[j].push_back(v + " " + t);
      }
    for(auto &s : ans[n])
      s = s.substr(1, s.length()-1);
    return ans[n];
  }
};


int main(){
  auto sol = Solution();
  unordered_set<string> dict = {"cat", "cats", "and", "sand", "dog"};
  auto ans = sol.wordBreak("catsanddog", dict);
  for(auto s : ans)
    cout << s << endl;
}
