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
  void dfs(int n, int r, int &ans,
           set<int> &col, set<int> &d1, set<int> &d2){
    if(r == n){
      ++ans; return;
    }
    for(int c=0; c<n; c++){
      if(col.find(c) == col.end() &&
         d1.find(c+r) == d1.end() &&
         d2.find(c-r) == d2.end()){
        col.insert(c); d1.insert(c+r); d2.insert(c-r);
        dfs(n, r+1, ans, col, d1, d2);
        col.erase(c); d1.erase(c+r); d2.erase(c-r);
      }
    }
  }
  int totalNQueens(int n) {
    set<int> col, d1, d2;
    int ans = 0;
    dfs(n, 0, ans, col, d1, d2);
    return ans;
  }
};

int main(){
  auto sol = Solution();
  cout << sol.totalNQueens(3);
}
