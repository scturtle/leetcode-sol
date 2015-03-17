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
  double pow(double x, int n) {
    bool neg = n < 0;
    if(neg) n = -n;
    if(n == 0) return 1;
    double ans = 1, a = x;
    while(n){
      if(n&1)
        ans *= a;
      a = a * a;
      n /= 2;
    }
    if(neg) ans = 1/ans;
    return ans;
  }
};

int main(){
  auto sol = Solution();
  cout << sol.pow(1.00000, -2147483648);
}
