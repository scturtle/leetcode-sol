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
  vector<vector<string>> partition(string s) {
    const int n = s.length();
    bool dp[n][n];
    fill_n(&dp[0][0], n * n, false);
    for(int k = 0; k<n; k++)
      for(int i=0; i+k<n; i++){
        int j = i+k;
        dp[i][j] = s[i] == s[j] && (j-i <= 1 || dp[i+1][j-1]);
      }
    vector<vector<vector<string> > > ans(n);
    for(int j=0; j<n; j++){
      for(int i=0; i<=j; i++)
        if(dp[i][j]){
          string sij = s.substr(i, j-i+1);
            if(i == 0)
              ans[j].push_back({sij});
            else{
              for(auto v : ans[i-1]){
                v.push_back(sij);
                ans[j].push_back(v);
              }
            }
        }
    }
    return ans[n-1];
  }
};

int main(){
  auto sol = Solution();
  vector<vector<string> > res = sol.partition("aab");
  for(auto &v : res){
    for(auto &s : v)
      cout << s << " ";
    cout << endl;
  }
}
