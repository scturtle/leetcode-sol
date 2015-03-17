#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <utility>
#include <map>
#include <string>
#include <unordered_map>
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
    int reverse(int x) {
      bool neg = x < 0;
      if(neg) x = -x;
      string s = to_string(x);
      std::reverse(s.begin(), s.end());
      if(neg) s = '-' + s;
      try{
        int rev_x = stoi(s);
        return rev_x;
      }catch(...){}
      return 0;
    }
};

int main(){
  auto sol = Solution();
  cout << sol.reverse(123);
}
