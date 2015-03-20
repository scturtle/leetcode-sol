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
  int splitVersion(string &s){
    if(s.empty()) return 0;
    int idx = s.find(".");
    if(idx == string::npos){
      int ans = atoi(s.c_str());
      s = "";
      return ans;
    } else {
      int ans = atoi(s.substr(0, idx).c_str());
      s = s.substr(idx+1);
      return ans;
    }
  }
  int compareVersion(string version1, string version2) {
    while(version1.length() || version2.length()){
      int v1 = splitVersion(version1);
      int v2 = splitVersion(version2);
      if(v1 < v2) return -1;
      else if(v1 > v2) return 1;
    }
    return 0;
  }
};

int main(){
  auto sol = Solution();
  string s = "";
}
