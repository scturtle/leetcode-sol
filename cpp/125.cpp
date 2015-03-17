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
  bool isPalindrome(string s) {
    int n = s.length();
    int i=0, j = n-1;
    while(1){
      while(i < n && !isalnum(s[i])) ++i;
      while(0 <= j && !isalnum(s[j])) --j;
      if(i >= j) return true;
      if(tolower(s[i]) != tolower(s[j])) return false;
      ++i; --j;
    }
  }
};

int main(){
  auto sol = Solution();
}
