#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
  int countPrimes(int n) {
    vector<bool> isprime(n, true);
    int upbound = ceil(sqrt(n));
    for(int i=2; i<=upbound; i++){
      if(isprime[i])
        for(int j=i*i; j < n; j+=i)
          isprime[j] = false;
    }
    int ans = 0;
    for(int i=2; i<n; i++) ans += isprime[i];
    return ans;
  }
};
