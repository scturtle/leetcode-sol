#include<iostream>
using namespace std;

class Solution {
public:
  int numSquares(int n) {
    int cnt[n+1];
    for(int i=0; i<=n; i++)
      cnt[i] = i;
    for(int i=0; i<=n; i++){
      for(int j=1; j*j<=i; j++){
        int sq = j*j;
        if(cnt[i-sq]+1 < cnt[i])
          cnt[i] = cnt[i-sq]+1;
      }
    }
    return cnt[n];
  }
};

int main(){
  Solution sol = Solution();
  cout << sol.numSquares(7927) << endl;
}
