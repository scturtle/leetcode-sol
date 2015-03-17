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
  int longestValidParentheses(string s) {
    int n = s.length();
    int dp[n];
    for(int i=0; i<n; i++){
      if(i == 0 || s[i] == '(' || i-dp[i-1]-1 < 0 || s[i-dp[i-1]-1] == ')'){
        dp[i] = 0;
        continue;
      }
      int j = i-dp[i-1]-2;
      dp[i] = dp[i-1] + 2 + (j>=0?dp[j]:0);
    }
    int ans = 0;
    for(int i=0; i<n; i++)
      ans = max(ans, dp[i]);
    return ans;
  }
};

int main(){
  auto sol = Solution();
  cout << sol.longestValidParentheses("())(())(()(((((())()())()())()((()(((()()))())(((()()(((())())))()()))))(()))))))(((((((())))(())(())(()()((()))))))()((())))))(())))))(");
}
