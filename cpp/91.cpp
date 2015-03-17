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
  int numDecodings(string s) {
    int n = s.length();
    if(!n) return 0;
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    for(int i=1; i<=n; i++){
      if(s[i-1] != '0')
        dp[i] = dp[i-1];
      if(i > 1 && (s[i-2] == '1' || (s[i-2] == '2' && s[i-1] >= '0' && s[i-1] <= '6')))
        dp[i] += dp[i-2];
    }
    return dp[n];
  }
};

int main(){
  auto sol = Solution();
  cout << sol.numDecodings("123");
}
