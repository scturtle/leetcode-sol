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
  int trap(int A[], int n) {
    int left[n], right[n];
    int mx = 0;
    for(int i=0; i<n; i++)
      left[i] = mx, mx = max(mx, A[i]);
    mx = 0;
    for(int i=n-1; i>=0; i--)
      right[i] = mx, mx = max(mx, A[i]);
    int v = 0;
    for(int i=0; i<n; i++){
      int t = min(left[i], right[i]) - A[i];
      v += t > 0 ? t : 0;
    }
    return v;
  }
};

int main(){
  auto sol = Solution();
  int A[12] = {0,1,0,2,1,0,1,3,2,1,2,1};
  cout << sol.trap(A, 12);
}
