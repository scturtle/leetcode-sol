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
  vector<vector<int> > generateMatrix(int n) {
    vector<vector<int> > ans;
    for(int i=0; i<n; i++){
      vector<int> v;
      for(int i=0; i<n; i++)
        v.push_back(0);
      ans.push_back(v);
    }
    int i=0, j=0, k=1, m=n;
    while(m > 1){
      for(int c=0; c<m-1; c++)
        ans[i][j] = k++, j += 1;
      for(int c=0; c<m-1; c++)
        ans[i][j] = k++, i += 1;
      for(int c=0; c<m-1; c++)
        ans[i][j] = k++, j -= 1;
      for(int c=0; c<m-1; c++)
        ans[i][j] = k++, i -= 1;
      ++i; ++j; m -= 2;
    }
    if(m)
      ans[i][j] = k;
    return ans;
  }
};

int main(){
  auto sol = Solution();
  auto ans = sol.generateMatrix(4);
  for(auto &v : ans)
    prints(v);
}
