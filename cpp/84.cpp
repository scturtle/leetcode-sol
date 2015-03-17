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
  int largestRectangleArea(vector<int> &height) {
    int n = height.size();
    int l[n], r[n], stack[n], top = 0;
    for(int i=0; i<n; i++){
      while(top && height[stack[top-1]] > height[i])
        r[stack[top-1]] = i, --top;
      l[i] = top ? stack[top-1] : -1 ;
      stack[top++] = i;
    }
    while(top) r[stack[top-1]] = n, --top;
    int ans = 0;
    for(int i=0; i<n; i++)
      ans = max(ans, height[i] * (r[i] - l[i] - 1));
    return ans;
  }
};

int main(){
  auto sol = Solution();
  vector<int> a = {2,1,5,6,2,3};
  cout << sol.largestRectangleArea(a);
}
