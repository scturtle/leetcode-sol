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
  void dfs(vector<pair<int,int>> &cand,
           int target, vector<vector<int>> &sols,
           uint idx, int sum, vector<int> &cur){
    if(sum == target){
      sols.push_back(cur);
      return;
    }
    if(idx == cand.size() || sum > target)
      return;
    dfs(cand, target, sols, idx+1, sum, cur);
    for(int c=0; c<cand[idx].second; c++){
      cur.push_back(cand[idx].first);
      sum += cand[idx].first;
      dfs(cand, target, sols, idx+1, sum, cur);
    }
    for(int i=0; i<cand[idx].second; i++)
      cur.pop_back();
  }
  vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
    map<int, int> cnt;
    for(auto &c : candidates) ++cnt[c];
    vector<pair<int, int>> cand;
    for(auto &t : cnt)
      cand.push_back(make_pair(t.first, t.second));
    vector<vector<int>> sols;
    vector<int> cur;
    dfs(cand, target, sols, 0, 0, cur);
    return sols;
  }
};

int main(){
  auto sol = Solution();
  vector<int> v = {1,2};
  auto res = sol.combinationSum2(v, 3);
  cout << res.size() << endl;
  for(auto &v : res)
    prints(v);
}
