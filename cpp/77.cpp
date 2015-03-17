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
  void dfs(int i, int n, int l, int k, vector<int> &cur, vector<vector<int> > &ans){
    if(l == k){
      ans.push_back(cur);
      return;
    }
    if(i > n)
      return;
    dfs(i+1, n, l, k, cur, ans);
    cur.push_back(i);
    dfs(i+1, n, l+1, k, cur, ans);
    cur.pop_back();
  }
  vector<vector<int> > combine(int n, int k) {
    vector<vector<int> > ans;
    vector<int> cur;
    dfs(1, n, 0, k, cur, ans);
    return ans;
  }
};

int main(){
  auto sol = Solution();
  for(auto &v : sol.combine(4, 2))
    prints(v);
}
