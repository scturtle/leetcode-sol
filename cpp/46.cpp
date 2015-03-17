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
  vector<vector<int> > permute(vector<int> &num) {
    vector<vector<int>> ans;
    int c = 1;
    for(int i=1; i<=num.size(); i++)
      c *= i;
    for(int i=0; i<c; i++){
      next_permutation(num.begin(), num.end());
      ans.push_back(num);
    }
    return ans;
  }
};

int main(){
  auto sol = Solution();
  vector<int> v = {1,2,3};
  auto ans = sol.permute(v);
  for(auto &t : ans)
    prints(t);
}
