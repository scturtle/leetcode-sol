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
  void dfs(uint i, const vector<vector<int>> &s,
           vector<int> &cur, vector<vector<int> > &ans){
    if(i == s.size()){
      ans.push_back(cur);
      return;
    }
    dfs(i+1, s, cur, ans);
    for(uint c=0; c<s[i].size(); ++c){
      cur.push_back(s[i][0]);
      dfs(i+1, s, cur, ans);
    }
    for(uint c=0; c<s[i].size(); ++c)
      cur.pop_back();
  }
  vector<vector<int> > subsetsWithDup(vector<int> &S) {
    vector<vector<int> > ans;
    if(S.size() == 0) return ans;
    sort(S.begin(), S.end());
    vector<vector<int> > s;
    for(uint i=0; i<S.size(); i++){
      if(s.size() == 0 || s.back()[0] != S[i])
        s.push_back({S[i]});
      else
        s.back().push_back(S[i]);
    }
    vector<int> cur;
    dfs(0, s, cur, ans);
    return ans;
  }
};

int main(){
  auto sol = Solution();
  vector<int> s = {2,2,2};
  auto ans = sol.subsetsWithDup(s);
  for(auto &t : ans){
    cout << "[";
    for(auto i : t)
      cout << i << " ";
    cout << "]" << endl;
  }
}
