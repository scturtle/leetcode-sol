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
  bool isScramble(string s1, string s2) {
    if(s1.length() != s2.length())
      return false;
    int n = s1.length();
    bool dp[n][n][n+1];
    for(int i=0; i<n; i++)
      for(int j=0; j<n; j++)
        for(int k=1; k<=n; k++)
          dp[i][j][k] = (k == 1 && s1[i] == s2[j]);
    for(int k=2; k<=n; k++){
      for(int i=0; i+k<=n; i++){
        for(int j=0; j+k<=n; j++){
          bool found = false;
          for(int l=1; l<k; l++)
            if((dp[i][j][l] && dp[i+l][j+l][k-l]) ||
              (dp[i][j+k-l][l] && dp[i+l][j][k-l]))
              found = true;
          dp[i][j][k] = found;
        }
      }
    }
    return dp[0][0][n];
  }
};

int main(){
  auto sol = Solution();
  cout << sol.isScramble("rgtae", "great");
}
