#include <vector>
using namespace std;

class Solution {
  void dfs(int k, int n, int i, vector<int> &cur, vector<vector<int>> &res){
    if(k == 0 && n == 0){
      res.push_back(cur);
      return;
    }
    if(k < 0 || n < 0 || i > 9)
      return;
    cur.push_back(i);
    dfs(k-1, n-i, i+1, cur, res);
    cur.pop_back();
    dfs(k, n, i+1, cur, res);
  }
public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> res;
    vector<int> cur;
    dfs(k, n, 1, cur, res);
    return res;
  }
};
