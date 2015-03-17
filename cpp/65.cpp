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
  bool isNumber(string s) {
    char* endptr;
    strtod(s.c_str(), &endptr);
    if(endptr == s.c_str())
      return false;
    for(;*endptr;++endptr)
      if(!isspace(*endptr)) return false;
    return true;
  }
};

int main(){
  auto sol = Solution();
}
