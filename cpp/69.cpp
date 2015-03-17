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
  int sqrt(int x) {
    if(x < 0)
      return 0;
    long l = 0, r = (long)x + 1;
    while(l+1 != r){
      long m = (l+r) / 2;
      // cout << l << " " << r << " " << m*m << endl;
      // invariance: l*l <= x && r*r > x
      if(m*m <= x)
        l = m;
      else
        r = m;
    }
    return l;
  }
};

int main(){
  auto sol = Solution();
  cout << sol.sqrt(2147483647);
}
