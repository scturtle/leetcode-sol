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
  int numDistinct(string S, string T) {
    int sn = S.length(), tn = T.length();
    int dp[sn+1][tn+1];
    for(int i=0; i<=sn; i++)
      for(int j=0; j<=tn; j++)
        dp[i][j] = 0;
    for(int i=0; i<=sn; i++)
      dp[i][0] = 1;
    for(int i=1; i<=sn; i++)
      for(int j=1; j<=tn; j++)
        dp[i][j] = dp[i-1][j] + (S[i-1] == T[j-1] ? dp[i-1][j-1] : 0);
    return dp[sn][tn];
  }
};

int main(){
  auto sol = Solution();
}
