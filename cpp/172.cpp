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
#include <sstream>
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
  int trailingZeroes(int n) {
    int ans = 0;
    while(n)
      ans += n/5, n/= 5;
    return ans;
  }
};


int main(){
  auto sol = Solution();
  cout << sol.trailingZeroes(5);
}
