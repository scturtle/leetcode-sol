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
  void setZeroes(vector<vector<int> > &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    bool first_row_to_be_zero = false;
    for(int j=0; j<n; j++)
      if(matrix[0][j] == 0)
        first_row_to_be_zero = true;
    bool first_column_to_be_zero = false;
    for(int i=0; i<m; i++)
      if(matrix[i][0] == 0)
        first_column_to_be_zero = true;
    for(int i=1; i<m; i++)
      for(int j=1; j<n; j++)
        if(matrix[i][j] == 0)
          matrix[0][j] = matrix[i][0] = 0;
    for(int i=1; i<m; i++)
      for(int j=1; j<n; j++)
        if(matrix[0][j] == 0 || matrix[i][0] == 0)
          matrix[i][j] = 0;
    if(first_row_to_be_zero)
      for(int j=0; j<n; j++)
        matrix[0][j] = 0;
    if(first_column_to_be_zero)
      for(int i=0; i<m; i++)
        matrix[i][0] = 0;
  }
};

int main(){
  auto sol = Solution();
}
