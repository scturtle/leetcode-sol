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
  bool canJump(int A[], int n) {
    int mx = 0;
    for(int i=0; i<n; i++)
      if(i <= mx)
        mx = max(mx, i+A[i]);
    return mx >= n-1;
  }
};

int main(){
  auto sol = Solution();
}
