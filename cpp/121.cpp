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
  int maxProfit(vector<int> &prices) {
    int ans = 0;
    if(prices.empty()) return 0;
    int mi = prices[0];
    for(uint i=1; i<prices.size(); ++i){
      ans = max(ans, prices[i] - mi);
      mi = min(mi, prices[i]);
    }
    return ans;
  }
};

int main(){
  auto sol = Solution();
}
