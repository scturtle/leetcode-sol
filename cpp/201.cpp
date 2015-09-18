#include <vector>
#include <utility>
#include <iostream>
using namespace std;

using ll = long long;
int cnt(ll n, ll i){
  ll itv = 1 << i;
  int ans = (n + 1) / (2 * itv) * itv;
    if((n + 1) % (2 * itv) > itv)
      ans += (n + 1) % (2 * itv) - itv;
    return ans;
}

class Solution {
public:
  ll rangeBitwiseAnd(int m, int n) {
    ll ans = 0;
    for(int i = 0; ((ll)1 << i) <= n; i ++){
      int cm = cnt(m-1, i), cn = cnt(n, i);
      if(cn-cm == n-m+1)
        ans += (ll)1 << i;
    }
    return ans;
  }
};

int main(){
  cout << Solution().rangeBitwiseAnd(1, 1) << endl;
}
