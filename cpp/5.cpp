#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <utility>
#include <map>
#include <unordered_map>
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
  string longestPalindrome(string s) {
    int n = s.size();
    if(!n) return "";
    bool dp[n][n+1];
    for(int i=0; i<n; i++)
      for(int j=0; j<=n; j++)
        dp[i][j] = j <= 1;
    int ri =0, rl = 1;
    for(int l=2; l<=n; l++){
      for(int i=0; i+l-1<n; i++){
        if(dp[i+1][l-2] && s[i] == s[i+l-1]){
          dp[i][l] = true;
          ri = i; rl = l;
        }
      }
    }
    return s.substr(ri, rl);
  }
};

int main(){
  auto sol = Solution();
  cout << sol.longestPalindrome("bb");
}
