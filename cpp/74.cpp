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
  bool searchMatrix(vector<vector<int> > &matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    if(matrix[0][0] > target)
      return false;
    int l = 0, r = m;
    while(l+1 != r){
      int m = (l+r) / 2;
      // matrix[l][0] <= target && matrix[r][0] > target
      if(matrix[m][0] <= target)
        l = m;
      else
        r = m;
    }
    int row = l;
    l = 0, r = n;
    while(l+1 != r){
      int m = (l+r) / 2;
      // matrix[row][l] <= target && matrix[row][r] > target
      if(matrix[row][m] <= target)
        l = m;
      else
        r = m;
    }
    return matrix[row][l] == target;
  }
};

int main(){
  auto sol = Solution();
}
