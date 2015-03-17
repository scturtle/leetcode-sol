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
  int minCut(string s) {
    const int n = s.length();
    bool p[n][n];
    fill_n(&p[0][0], n * n, false);
    for(int k = 0; k<n; k++)
      for(int i=0; i+k<n; i++){
        int j = i+k;
        p[i][j] = s[i] == s[j] && (j-i <= 1 || p[i+1][j-1]);
      }
    vector<int> dp(n, n-1);
    for(int j=0; j<n; j++)
      for(int i=0; i<=j; i++)
        if(p[i][j])
          dp[j] = min(dp[j], i > 0 ? 1 + dp[i-1] : 0);
    return dp[n-1];
  }
};

int main(){
  auto sol = Solution();
  cout << sol.minCut("aab");
}
