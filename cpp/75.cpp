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
  void sortColors(int A[], int n) {
    int cnt[3] = {0, 0, 0};
    for(int i=0; i<n; i++)
      ++cnt[A[i]];
    int i=0;
    for(int k=0; k<3; k++)
      while(cnt[k]--)
        A[i++] = k;
  }
};

int main(){
  auto sol = Solution();
}
