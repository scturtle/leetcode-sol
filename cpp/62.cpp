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
    int uniquePaths(int m, int n) {
      vector<int> dp(n, 0);
      dp[0] = 1;
      for(int i=0; i<m; i++)
        for(int j=1; j<n; j++)
          dp[j] += dp[j-1];
      return dp[n-1];
    }
};


int main(){
  auto sol = Solution();
  cout << sol.uniquePaths(36, 7);
}
