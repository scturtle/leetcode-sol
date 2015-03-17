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
  void dfs(int n, int r, vector<string> &cur, vector<vector<string>> &ans,
           set<int> &col, set<int> &d1, set<int> &d2){
    if(r == n){
      ans.push_back(cur);
      return;
    }
    for(int c=0; c<n; c++){
      if(col.find(c) == col.end() &&
         d1.find(c+r) == d1.end() &&
         d2.find(c-r) == d2.end()){
        string s;
        for(int i=0; i<c; i++) s += '.';
        s += 'Q';
        for(int i=0; i<n-1-c; i++) s += '.';
        cur.push_back(s);
        col.insert(c); d1.insert(c+r); d2.insert(c-r);
        dfs(n, r+1, cur, ans, col, d1, d2);
        col.erase(c); d1.erase(c+r); d2.erase(c-r);
        cur.pop_back();
      }
    }
  }
  vector<vector<string> > solveNQueens(int n) {
    set<int> col, d1, d2;
    vector<vector<string>> ans;
    vector<string> cur;
    dfs(n, 0, cur, ans, col, d1, d2);
    return ans;
  }
};

int main(){
  auto sol = Solution();
  auto ans = sol.solveNQueens(4);
  for(auto &t : ans){
    for(auto &s : t)
      cout << s << endl;
    cout << endl;
  }
}
