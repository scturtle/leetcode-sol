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
  int findMin(vector<int> &num) {
    int n = num.size();
    if(num[0] < num[n-1] || n == 1)
      return num[0];
    int l = 0, r = n-1;
    while(l+1 != r){
      int m = (l+r)/2;
      // num[l] >= num[0] && num[r] < num[0];
      if(num[m] < num[0])
        r = m;
      else
        l = m;
    }
    return num[r];
  }
};

int main(){
  auto sol = Solution();
}
