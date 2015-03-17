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
  void dfs(uint i, const vector<int> &s, vector<int> &cur, vector<vector<int> > &ans){
    if(i == s.size()){
      ans.push_back(cur);
      return;
    }
    dfs(i+1, s, cur, ans);
    cur.push_back(s[i]);
    dfs(i+1, s, cur, ans);
    cur.pop_back();
  }
  vector<vector<int> > subsets(vector<int> &S) {
    vector<vector<int> > ans;
    if(S.size() == 0) return ans;
    sort(S.begin(), S.end());
    vector<int> cur;
    dfs(0, S, cur, ans);
    return ans;
  }
};


int main(){
  auto sol = Solution();
}
