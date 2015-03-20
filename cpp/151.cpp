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
  void reverseWords(string &s) {
    vector<string> v;
    uint i = 0;
    while(i < s.length() && s[i] == ' ') ++i;
    while(i < s.length()){
      int j = s.find(" ", i);
      if(j == string::npos) j = s.length();
      if(i != j)
        v.push_back(s.substr(i, j-i));
      i = j+1;
    }
    stringstream t;
    if(v.size() == 0)
      s = "";
    else {
      for(auto w=v.rbegin(); w!=v.rend(); ++w) t << " " << *w;
      s = t.str().substr(1, s.length());
    }
  }
};

int main(){
  auto sol = Solution();
  string s = " ";
  sol.reverseWords(s);
  cout << s;
}
