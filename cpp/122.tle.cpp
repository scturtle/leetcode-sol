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
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    if(n == 0) return 0;
    int dp[n+1];
    dp[0] = dp[1] = 0;
    for(int i=2; i<=n; i++){
      dp[i] = 0;
      for(int j=0; j<i-1; j++)
        dp[i] = max(dp[i], dp[j] + prices[i-1] - prices[j]);
    }
    return dp[n];
  }
};

int main(){
  auto sol = Solution();
  vector<int> v = {1,2,1,2,1,2};
  cout << sol.maxProfit(v);
}
