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
#include <sstream>
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
  string fractionToDecimal(long long nu, long long de) {
    int neg = 1;
    if(nu == 0) return "0";
    if(nu < 0) neg = -neg, nu = -nu;
    if(de < 0) neg = -neg, de = -de;
    string sign = neg == -1 ? "-" : "";
    string ans;
    ans += to_string(nu / de);
    nu %= de;
    if(nu == 0)
      return sign + ans;
    else
      ans += ".";
    unordered_map<int, int> saw;
    while(nu){
      if(saw.find(nu) != saw.end())
        return sign + ans.substr(0, saw[nu]) + "(" + ans.substr(saw[nu]) + ")";
      ans += to_string(10 * nu / de);
      saw[nu] = ans.length() - 1;
      nu = (10 * nu) % de;
    }
    return sign + ans;
  }
};

int main(){
  auto sol = Solution();
  cout << sol.fractionToDecimal(-1, -2147483648);
}
