#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <utility>
#include <map>
#include <unordered_map>
using namespace std;

template<typename T>
void prints(vector<T> &v){
  cout << "[";
  for(uint i=0; i<v.size()-1; ++i)
    cout << v[i] << ", ";
  if(v.size()) cout << v[v.size()-1];
  cout << "]\n";
}

// struct ListNode {
//   int val;
//   ListNode *next;
//   ListNode(int x) : val(x), next(NULL) {}
// };

class Solution {
public:
  double findMedianSortedArrays(int A[], int m, int B[], int n) {
    vector<int> dst;
    for(int i=0; i<m; i++)
      dst.push_back(A[i]);
    for(int i=0; i<n; i++)
      dst.push_back(B[i]);
    auto middle = dst.begin();
    for(int i=0; i<m; i++)
      ++middle;
    inplace_merge(dst.begin(), middle, dst.end());
    prints(dst);
    if((m+n)&1)
      return dst[(m+n)/2];
    else
      return (dst[(m+n)/2-1]+dst[(m+n)/2])/2.0;
  }
};

int main(){
  auto sol = Solution();
  int a[]{};
  int b[]{2,3};
  cout << sol.findMedianSortedArrays(a, 0, b, 2);
  return 0;
}
