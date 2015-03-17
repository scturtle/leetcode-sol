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
    for(int i=1; i<prices.size(); i++)
      ans += max(0, prices[i] - prices[i-1]);
    return ans;
  }
};

int main(){
  auto sol = Solution();
  vector<int> v = {1,2,1,2,1,2};
  cout << sol.maxProfit(v);
}
