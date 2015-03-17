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
    int n = prices.size();
    if(n <= 1) return 0;
    int mi = prices[0], mx = -prices[0];
    int once[n], twice[n];
    once[0] = twice[0] = 0;
    for(int i=1; i<n; i++){
      once[i] = max(once[i-1], prices[i] - mi);
      twice[i] = max(twice[i-1], mx + prices[i]);
      cout << once[i] << " " << twice[i] << endl;
      mi = min(mi, prices[i]);
      mx = max(mx, once[i-1] - prices[i]);
    }
    return max(once[n-1], twice[n-1]);
  }
};

int main(){
  auto sol = Solution();
  vector<int> v = {2,1,4,5,2,9,7};
  cout << sol.maxProfit(v);
}
