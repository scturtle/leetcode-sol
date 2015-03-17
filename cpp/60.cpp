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
  string getPermutation(int n, int k) {
    int f[n+1];
    f[0] = 1;
    for(int i=1; i<=n; i++)
      f[i] = f[i-1] * i;
    string ans;
    vector<int> digits = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    --k;
    for(int i=n-1; i>=0; --i){
      int idx = k / f[i];
      k %= f[i];
      ans += '0' + digits[idx];
      digits.erase(digits.begin() + idx,digits.begin() + idx + 1);
    }
    return ans;
  }
};

int main(){
  auto sol = Solution();
  cout << sol.getPermutation(3, 5);
}
