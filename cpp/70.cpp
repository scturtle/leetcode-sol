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
  int climbStairs(int n) {
    int a = 0, b = 1;
    for(int i=0; i<n; i++){
      int t = a;
      a = b; b = t + b;
    }
    return b;
  }
};

int main(){
  auto sol = Solution();
  cout << sol.climbStairs(3);
}
