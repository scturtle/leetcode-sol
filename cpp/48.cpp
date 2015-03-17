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
  void rotate(vector<vector<int> > &matrix) {
    int n = matrix.size();
    if(!n) return;
    for(int i=0; i<n; i++)
      reverse(matrix[i].begin(), matrix[i].end());
    for(int i=0; i<n; i++)
      for(int j=0; j+i<n; j++){
        int k = n-1-j, l = n-1-i;
        cout << i << j << k << l << endl;
        int t = matrix[i][j];
        matrix[i][j] = matrix[k][l];
        matrix[k][l] = t;
      }
  }
};

int main(){
  auto sol = Solution();
  vector<vector<int>> m = {{1,2},{3,4}};
  sol.rotate(m);
  for(auto &t : m)
    prints(t);
}
