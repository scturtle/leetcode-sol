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
  int minDistance(string word1, string word2) {
    int n1 = word1.length(), n2 = word2.length();
    int dp[n1+1][n2+1];
    for(int i=0; i<=n1; i++)
      dp[i][0] = i;
    for(int j=0; j<=n2; j++)
      dp[0][j] = j;
    for(int i=1; i<=n1; i++)
      for(int j=1; j<=n2; j++)
        dp[i][j] = min(dp[i-1][j-1] + (word1[i-1]==word2[j-1]?0:1),
                       min(dp[i-1][j] + 1, dp[i][j-1] + 1));
    return dp[n1][n2];
  }
};

int main(){
  auto sol = Solution();
  cout << sol.minDistance("111", "1212");
}
