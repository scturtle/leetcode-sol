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
  bool isInterleave(string s1, string s2, string s3) {
    int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
    if(n1 + n2 != n3)
      return false;
    bool dp[n1+1][n2+1];
    for(int i=0; i<=n1; i++)
      for(int j=0; j<=n2; j++){
        if(!i && !j)
          dp[i][j] = true;
        else
          dp[i][j] = (s1[i-1] == s3[i+j-1] && dp[i-1][j]) || (s2[j-1] == s3[i+j-1] && dp[i][j-1]);
        }
    return dp[n1][n2];
  }
};

int main(){
  auto sol = Solution();
  cout << sol.isInterleave("aabcc", "dbbca", "aadbbcbcac");
  cout << sol.isInterleave("aabcc", "dbbca", "aadbbbaccc");
}
