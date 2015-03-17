#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <utility>
#include <map>
#include <set>
#include <string>
#include <deque>
#include <unordered_map>
#include <unordered_set>
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
  bool wordBreak(string s, unordered_set<string> &dict) {
    int n = s.length();
    bool dp[n+1];
    dp[0] = true;
    for(int j=1; j<=n; j++){
      dp[j] = false;
      for(int i=0; i<j; i++)
        if(dp[i] && dict.find(s.substr(i,j-i)) != dict.end()){
          dp[j] = true;
          break;
        }
    }
    // for(int i=0; i<n; i++) cout << dp[i]; cout << endl;
    return dp[n];
  }
};

int main(){
  auto sol = Solution();
  unordered_set<string> dict = {"aaaa", "aaa"};
  sol.wordBreak("aaaaaaa", dict);
}
