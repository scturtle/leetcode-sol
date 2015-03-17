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
  int search(int A[], int n, int target) {
    // find the fist one less than A[0]
    int l = 0, r = n;
    if(A[0] > A[n-1]){
      int pivot;
      while(l+1 != r){
        int m = (l + r) / 2;
        // A[l] >= A[0] && A[r] < A[0]
        if(A[m] >= A[0])
          l = m;
        else
          r = m;
      }
      pivot = r;
      // cout << pivot << endl;
      if(target >= A[0])
        l = 0, r = pivot;
      else
        l = pivot, r = n;
    }
    if(target < A[l] || target > A[r-1]) return -1;
    while(l+1 != r){
      int m = (l + r) / 2;
      if(A[m] <= target)
        l = m;
      else
        r = m;
    }
    return A[l] == target ? l : -1;
  }
};

int main(){
  auto sol = Solution();
  // int a[] = {4,5,6,7,0,1,2};
  // int a[] = {0,1,2,4,5,6,7};
  int a[] = {1, 3};
  cout << sol.search(a, 2, 2);
}
