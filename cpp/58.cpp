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
  int lengthOfLastWord(const char *s) {
    int last = 0, cur = 0;
    for(;*s;++s){
      cout << last;
      if(*s == ' '){
        if(cur) last = cur;
        cur = 0;
      }else
        ++cur;
    }
    return cur ? cur : last;
  }
};

int main(){
  auto sol = Solution();
  cout << sol.lengthOfLastWord("b   a   ");
}
