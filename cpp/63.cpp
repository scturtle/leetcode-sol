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
  int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<int> dp(n, 0);
    if(obstacleGrid[0][0] == 0)
      dp[0] = 1;
    for(int i=0; i<m; i++){
      if((i && obstacleGrid[i-1][0]) || obstacleGrid[i][0])
        dp[0] = 0;
      for(int j=1; j<n; j++)
        if(obstacleGrid[i][j])
          dp[j] = 0;
        else
          dp[j] = (i && obstacleGrid[i-1][j] == 0 ? dp[j] : 0) +
            (obstacleGrid[i][j-1] == 0 ? dp[j-1] : 0);
    }
    return dp[n-1];
  }
};

int main(){
  auto sol = Solution();
}
