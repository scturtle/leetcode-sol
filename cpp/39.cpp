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
  void dfs(vector<int> &cand, int target, vector<vector<int>> &sols,
           uint idx, int sum, vector<int> &cur){
    if(sum == target){
      sols.push_back(cur);
      return;
    }
    if(idx == cand.size() || sum > target)
      return;
    int c = 0;
    while(sum <= target){
      dfs(cand, target, sols, idx+1, sum, cur);
      ++c; cur.push_back(cand[idx]); sum += cand[idx];
    }
    for(int i=0; i<c; i++)
      cur.pop_back();
  }
  vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> sols;
    vector<int> cur;
    dfs(candidates, target, sols, 0, 0, cur);
    return sols;
  }
};

int main(){
  auto sol = Solution();
  vector<int> v = {2,3,6,7};
  auto res = sol.combinationSum(v, 7);
  cout << res.size() << endl;
  for(auto &v : res)
    prints(v);
}
