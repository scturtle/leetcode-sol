#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <utility>
#include <map>
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
  int maxArea(vector<int> &height) {
    int n = height.size();
    int ans = 0, l = 0, r = n-1;
    while(l < r){
      int v = min(height[l], height[r]) * (r-l);
      ans = max(ans, v);
      if(height[l] <= height[r])
        ++l;
      else
        --r;
    }
    return ans;
  }
};


int main(){
  auto sol = Solution();
}
