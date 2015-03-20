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
  int titleToNumber(string s) {
    int t = 1, ans = 0;
    reverse(s.begin(), s.end());
    for(char c : s){
      ans += (c - 'A' + 1) * t;
      t *= 26;
    }
    return ans;
  }
};

int main(){
  auto sol = Solution();
  cout << sol.titleToNumber("AB");
}
