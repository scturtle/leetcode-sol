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
  int minPathSum(vector<vector<int> > &grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<int> dp(n, 0);
    for(int i = 0; i < m; i++){
      for(int j = 0; j < n; j++){
        if(!i && !j)
          dp[j] = grid[i][j];
        else
          dp[j] = grid[i][j] + min(i?dp[j]:INT_MAX, j?dp[j-1]:INT_MAX);
      }
      prints(dp);
    }
    return dp[n-1];
  }
};

int main(){
  auto sol = Solution();
  vector<vector<int> > v={{1,2},{1,1}};
  sol.minPathSum(v);
}
