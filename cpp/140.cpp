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
    vector<string> res;
    vector<bool> canseg(n+1, false);
    vector<vector<string> > ans(n+1);

    canseg[n] = true;
    for(int i=n-1; i>=0; --i){
      for(int j=i+1; j<=n; ++j)
        if(canseg[j] && dict.find(s.substr(i, j-i)) != dict.end())
          canseg[i] = true;
    }
    if(!canseg[n]) return res;

    ans[0].push_back({""});
    for(int j=1; j<=n; j++){
      if(!canseg[j]) continue;
      for(int i=0; i<j; i++){
        string t = s.substr(i, j-i);
        if(dict.find(t) != dict.end())
          for(auto v : ans[i])
            ans[j].push_back(v + " " + t);
      }
    }
    for(auto &s : ans[n]) res.push_back(s.substr(1, s.length()-1));
    return res;
  }
};


int main(){
  auto sol = Solution();
  unordered_set<string> dict = {"cat", "cats", "and", "sand", "dog"};
  auto ans = sol.wordBreak("catsanddog", dict);
  for(auto s : ans)
    cout << s << endl;
}
