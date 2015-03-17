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
  vector<int> spiralOrder(vector<vector<int> > &matrix) {
    int n = matrix.size();
    if(!n) return vector<int>{};
    int m = matrix[0].size();
    if(!m) return vector<int>{};
    int i=0, j=0, ki = n, kj = m;
    vector<int> v;
    while(ki > 1 && kj > 1){
      for(int c=0; c<kj-1; c++){
        v.push_back(matrix[i][j]);
        j += 1;
      }
      for(int c=0; c<ki-1; c++){
        v.push_back(matrix[i][j]);
        i += 1;
      }
      for(int c=0; c<kj-1; c++){
        v.push_back(matrix[i][j]);
        j -= 1;
      }
      for(int c=0; c<ki-1; c++){
        v.push_back(matrix[i][j]);
        i -= 1;
      }
      i += 1; j += 1; ki -= 2; kj -= 2;
    }
    if(ki == 1 && kj >= 1)
      for(int c = 0; c < kj; c++)
        v.push_back(matrix[i][j]), ++j;
    else if(ki > 1 && kj == 1)
      for(int c = 0; c < ki; c++)
        v.push_back(matrix[i][j]), ++i;
    return v;
  }
};

int main(){
  auto sol = Solution();
  vector<vector<int> > v = {{1,2,3},{4,5,6},{7,8,9}};
  for(auto &v : sol.spiralOrder(v))
    cout << v << " ";
}
