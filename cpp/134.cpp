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
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    if(accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0))
      return -1;
    int start = 0, vol = 0;
    for(uint i=0; i<gas.size(); i++){
      vol += gas[i] - cost[i];
      if(vol < 0){
        start = i+1;
        vol = 0;
      }
    }
    return start;
  }
};

int main(){
  auto sol = Solution();
}
