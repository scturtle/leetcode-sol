#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <utility>
#include <map>
#include <string>
#include <unordered_map>
#include <climits>
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
  bool isPalindrome(int x) {
    if(x<0) x=-x;
    string s = to_string(x);
    string rev_s(s);
    reverse(begin(rev_s), end(rev_s));
    return !s.compare(rev_s);
  }
};

int main(){
  auto sol = Solution();
  cout << sol.isPalindrome(9999999);
}
