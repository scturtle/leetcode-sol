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
  string next_nseq(string s){
    string ans;
    auto i = s.begin();
    while(i != s.end()){
      int cnt = 0;
      char cur = *i;
      while(i != s.end() && *i == cur)
        ++cnt, ++i;
      ans += to_string(cnt) + cur;
    }
    return ans;
  }

  string countAndSay(int n) {
    string s = "1";
    for(int i=1; i<n; i++)
      s = next_nseq(s);
    return s;
  }
};

int main(){
  auto sol = Solution();
  for(int i=1; i<=5; i++)
    cout << sol.countAndSay(i) << endl;
}
