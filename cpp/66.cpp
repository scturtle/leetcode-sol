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
  vector<int> plusOne(vector<int> &digits) {
    int n = digits.size(), ad = 1;
    vector<int> ans(n, 0);
    for(int i=n-1; i>=0; --i){
      ans[i] = digits[i] + ad;
      if(ans[i] == 10)
        ans[i] = 0, ad = 1;
      else
        ad = 0;
    }
    if(ad)
      ans.insert(ans.begin(), 1);
    return ans;
  }
};

int main(){
  auto sol = Solution();
  vector<int> v = {0};
  auto ans = sol.plusOne(v);
  prints(ans);
}
