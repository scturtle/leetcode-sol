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
#include <sstream>
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
  int hash(string &s, int st){
    int ans = 0, t = 1;
    for(int i=9; i>=0; --i){
      int c;
      switch(s[st + i]){
      case 'A': c = 0; break;
      case 'C': c = 1; break;
      case 'G': c = 2; break;
      case 'T': c = 3; break;
      }
      ans += c * t;
      t <<= 2;
    }
    return ans;
  }
  vector<string> findRepeatedDnaSequences(string s) {
    int m[1050000];
    for(int i=0; i<1050000; i++)
      m[i] = 0;
    vector<string> ans;
    int n = s.length();
    for(int i=0; i+10<=n; i++){
      int t = hash(s, i);
      ++m[t];
      if(m[t] == 2)
        ans.push_back(s.substr(i, 10));
    }
    return ans;
  }
};


int main(){
  auto sol = Solution();
}
