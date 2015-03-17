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
  vector<int> searchRange(int A[], int n, int target) {
    if(n == 0)
      return vector<int>{-1, -1};
    int l = distance(A, lower_bound(A, A+n, target));
    int r = distance(A, prev(upper_bound(A, A+n, target)));
    return A[l] == target ? vector<int>{l, r} : vector<int>{-1, -1};
  }
};


int main(){
  auto sol = Solution();
  // int a[] = {4,5,6,7,0,1,2};
  // int a[] = {0,1,2,4,5,6,7};
  // int a[] = {1, 3};
  // cout << sol.search(a, 2, 2);
}
