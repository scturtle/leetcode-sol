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
  int maxSubArray(int A[], int n) {
    int ans = INT_MIN;
    int cur = 0;
    for(int i=0; i<n; i++){
      if(cur < 0)
        cur = 0;
      cur += A[i];
      ans = max(ans, cur);
    }
    return ans;
  }
};

int main(){
  auto sol = Solution();
  int a[3] = {-2, 1};
  cout << sol.maxSubArray(a, 2);
}
