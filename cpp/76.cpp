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
  string minWindow(string S, string T) {
    map<char, int> tcnt;
    for(auto &c : T) ++tcnt[c];
    map<char, int> scnt;
    int l = 0, r = 0, todo = tcnt.size(),
      ans = INT_MAX, ansl = -1, ansr = -1;
    while(r < S.length()){
      ++scnt[S[r]];
      if(scnt[S[r]] == tcnt[S[r]])
        --todo;
      ++r;
      if(todo == 0){
        while(scnt[S[l]] > tcnt[S[l]])
          --scnt[S[l++]];
        if(r-l < ans)
          ans = r-l, ansl = l, ansr = r;
        --scnt[S[l++]]; ++todo;
      }
    }
    if(ans != INT_MAX)
      return S.substr(ansl, ansr - ansl);
    else
      return "";
  }
};

int main(){
  auto sol = Solution();
  cout << sol.minWindow("a", "aa");
}
