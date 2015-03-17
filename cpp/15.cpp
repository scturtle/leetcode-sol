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
  vector<vector<int> > threeSum(vector<int> &num) {
    vector<vector<int>> v;
    if(num.size() < 3) return v;
    sort(begin(num), end(num));
    for(auto i = num.begin(); i < num.end()-2; ++i){
      auto j = i+1, k = num.end()-1;
      if (i > num.begin() && *i == *(i-1)) continue;
      while(j < k){
        int sum = *i + *j + *k;
        if(sum == 0){
          v.push_back({*i, *j, *k});
          ++j; --k;
          while(*j == *(j - 1) && *k == *(k + 1) && j < k) ++j;
        } else if (sum < 0){++j;}
        else{--k;}
      }
    }
    return v;
  }
};

int main(){
  auto sol = Solution();
  vector<int> vec = {-1,-1,0,0,1,1};
  auto res = sol.threeSum(vec);
  for(auto& v : res) prints(v);
}
