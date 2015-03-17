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
  int threeSumClosest(vector<int> &num, int target) {
    if(num.size() <= 3)
      return accumulate(num.begin(), num.end(), 0);
    sort(num.begin(), num.end());
    int best = accumulate(num.begin(), num.begin()+3, 0);
    for(auto i = num.begin(); i != num.end(); ++i){
      auto j = i+1, k = num.end()-1;
      while(j < k){
        int cur = *i + *j + *k;
        if(abs(cur - target) < abs(best - target))
          best = cur;
        else if(cur < target)
          ++j;
        else
          --k;
      }
    }
    return best;
  }
};

int main(){
  auto sol = Solution();
  vector<int> vec = {-1, 2, 1, -4};
  cout << sol.threeSumClosest(vec, 1);
}
