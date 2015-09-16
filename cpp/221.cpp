#include<vector>
#include<iostream>
using namespace std;

class Solution {
  int helper(int l[], int n){
    int lb[n], rb[n], s[n], top=0;
    for(int i=0; i<n; i++){
      while(top && l[s[top-1]] > l[i])
        rb[s[--top]] = i;
      s[top++] = i;
    }
    while(top) rb[s[--top]] = n;
    for(int i=n-1; i>=0; i--){
      while(top && l[s[top-1]] > l[i])
        lb[s[--top]] = i;
      s[top++] = i;
    }
    while(top) lb[s[--top]] = -1;
    int ans = 0;
    for(int i=0; i<n; i++){
      int t = min(rb[i]- lb[i] - 1, l[i]);
      ans = max(ans, t*t);
    }
    return ans;
  }
public:
  int maximalSquare(vector<vector<char>>& matrix) {
    int n = matrix.size();
    if(n == 0) return 0;
    int m = matrix[0].size();
    int l[m];
    for(int i=0; i<m; i++) l[i] = 0;
    int ans = 0;
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++)
        if(matrix[i][j] == '0')
          l[j] = 0;
        else ++l[j];
      ans = max(ans, helper(l, m));
    }
    return ans;
  }
};

int main(){
  vector<vector<char>> m = {{'0', '0'}};
  cout << Solution().maximalSquare(m) << endl;
}
