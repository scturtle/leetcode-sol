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
  vector<vector<int> > generate(int n) {
    vector<vector<int> > ans;
    if(n == 0)
      return ans;
    ans.push_back({1});
    for(int i=2; i<=n; i++){
      vector<int> t = {1};
      for(int j=1; j<=i-2; j++)
        t.push_back(ans.back()[j-1] + ans.back()[j]);
      t.push_back(1);
      ans.push_back(t);
    }
    return ans;
  }
};

int main(){
  auto sol = Solution();
  sol.generate(3);
}
