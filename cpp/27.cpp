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
  int removeElement(int A[], int n, int elem) {
    int a, b;
    for(a = 0, b = 0; b < n; b++){
      if(A[b] == elem) continue;
      A[a++] = A[b];
    }
    return a;
  }
};

int main(){
  auto sol = Solution();
}
