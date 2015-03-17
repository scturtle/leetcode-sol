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
  vector<vector<int> > fourSum(vector<int> &num, int target) {
    vector<vector<int>> ans;
    if(num.size() < 4) return ans;
    sort(num.begin(), num.end());
    for(auto i=num.begin(); i<num.end()-3; ++i){
      if(i != num.begin() && *i == *(i-1)) continue;
      for(auto j=i+1; j<num.end()-2; ++j){
        if(j != i+1 && *j == *(j-1)) continue;
        auto k = j+1, l = num.end()-1;
        while(k < l){
          int cur = *i + *j + *k + *l;
          if(cur == target){
            ans.push_back({*i, *j, *k, *l});
            ++k; --l;
            while(*k == *(k-1) && *l == *(l+1) && k < l) ++k, --l;
          } else if(cur < target)
            ++k;
          else
            --l;
        }
      }
    }
    return ans;
  }
};

int main(){
  auto sol = Solution();
  // vector<int> v = {1,0,-1,0,-2,2};
  vector<int> v = {0,0,0,0};
  for(auto& t : sol.fourSum(v, 0))
    prints(t);
}
