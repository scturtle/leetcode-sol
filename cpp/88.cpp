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
  void merge(int A[], int m, int B[], int n) {
    for(int k=m+n-1; k>=0; --k)
      if(n == 0 || (m > 0 && A[m-1] > B[n-1]))
        A[k] = A[m-1], --m;
      else
        A[k] = B[n-1], --n;
  }
};

int main(){
  auto sol = Solution();
}
