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
  int atoi(string str) {
    errno = 0;
    long x = strtol(str.c_str(), NULL, 10);
    switch (errno) {
      case ERANGE:
        return str.find('-')!=string::npos?INT32_MIN:INT32_MAX;
      case EINVAL:
        return 0;
    }
    if(x < INT32_MIN) return INT32_MIN;
    if(x > INT32_MAX) return INT32_MAX;
    return x;
  }
};

int main(){
  auto sol = Solution();
  cout << sol.atoi("99999999999999999999999999999999");
}
