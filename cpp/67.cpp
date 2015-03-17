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
  string addBinary(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    string ans;
    int ad = 0;
    const char *i = a.c_str(), *j = b.c_str();
    while(*i || *j){
      int t = (i&&(*i=='1')?1:0) + (j&&(*j=='1')?1:0) + ad;
      if(t == 0)
        ans += '0', ad = 0;
      else if(t == 1)
        ans += '1', ad = 0;
      else if(t == 2)
        ans += '0', ad = 1;
      else
        ans += '1', ad = 1;
      if(*i) ++i; if(*j) ++j;
    }
    if(ad)
      ans += '1';
    reverse(ans.begin(), ans.end());
    return ans;
  }
};

int main(){
  auto sol = Solution();
  cout << sol.addBinary("0", "1");
}
