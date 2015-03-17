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
  int singleNumber(int A[], int n) {
    int two = 0, one = 0, three;
    for(int i=0; i<n; i++){
      two ^= one & A[i];
      one ^= A[i];
      three = one & two;
      one = one & (~three);
      two = two & (~three);
    }
    return one;
  }
};

int main(){
  auto sol = Solution();
  int a[7] = {1,1,1,5,3,3,3};
  cout << sol.singleNumber(a, 7);
}
