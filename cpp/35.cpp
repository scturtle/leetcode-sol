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
  int searchInsert(int A[], int n, int target) {
    int l = distance(A, lower_bound(A, A+n, target));
    return l;
  }
};


int main(){
  auto sol = Solution();
  int a[] = {1,3,5,6};
  cout << sol.searchInsert(a, 4, 4);
}
