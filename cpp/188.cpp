#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <utility>
#include <map>
#include <set>
#include <string>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <numeric>
#include <sstream>
using namespace std;

template<typename T>
void prints(vector<T> &v){
  cout << "[";
  for(uint i=0; i<v.size()-1; ++i)
    cout << v[i] << ", ";
  if(v.size()) cout << v[v.size()-1];
  cout << "]\n";
}

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int ans = 0;
    for(int i=1; i<prices.size(); i++)
      ans += max(0, prices[i] - prices[i-1]);
    return ans;
  }
  int maxProfit(int k, vector<int> &prices) {
    int n = prices.size();
    if(n < 2) return 0;
    if(2*k >= n) return maxProfit(prices);
    int dp[n][k];
    for(int j=0; j<k; j++)
      dp[0][j] = 0;
    int mi = prices[0];
    int mx[k-1];
    for(int j=0; j<k-1; j++)
      mx[j] = -prices[0];
    for(int i=1; i<n; i++){
      dp[i][0] = max(dp[i-1][0], prices[i] - mi);
      for(int j=1; j<k; j++)
        dp[i][j] = max(dp[i-1][j], mx[j-1] + prices[i]);
      mi = min(mi, prices[i]);
      for(int j=0; j<k-1; j++)
        mx[j] = max(mx[j], dp[i-1][j] - prices[i]);
    }
    int ans = 0;
    for(int j=0; j<k; j++) ans = max(ans, dp[n-1][j]);
    return ans;
  }
};

int main(){
  auto sol = Solution();
  vector<int> p = {1,2,1,2,1,2,1,2};
  cout << sol.maxProfit(3, p);
}
