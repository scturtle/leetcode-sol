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
  int numTrees(int n) {
    vector<int> dp(n+1, 0);
    dp[0] = dp[1] = 1;
    for(int i=2; i<=n; i++)
      for(int l=0; l<i; l++)
        dp[i] += dp[l] * dp[i-1-l];
    return dp[n];
  }
};

int main(){
  auto sol = Solution();
  cout << sol.numTrees(3);
}
