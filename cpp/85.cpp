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
  int maximalRectangle(vector<vector<char> > &matrix) {
    int m = matrix.size();
    if(!m) return 0;
    int n = matrix[0].size();
    int dp[n][n];
    for(int i=0; i<n; i++)
      for(int j=0; j<n; j++)
        dp[i][j] = 0;
    int ans = 0;
    for(int k=0; k<m; k++){
      for(int i=0; i<n; i++)
        for(int j=i; j<n; j++){
          if(i == j)
            dp[i][j] = matrix[k][j] == '1' ? dp[i][j]+1 : 0;
          else
            dp[i][j] = dp[i][j-1] && matrix[k][j] == '1' ? dp[i][j]+1 : 0;
          ans = max(ans, dp[i][j] * (j-i+1));
        }
    }
    return ans;
  }
};

int main(){
  auto sol = Solution();
  vector<vector<char> > m = {{'0', '0'}};
  cout << sol.maximalRectangle(m);
}
