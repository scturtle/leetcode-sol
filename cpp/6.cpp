#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <utility>
#include <map>
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
  string convert(string s, int nRows) {
    if(nRows == 1) return s;
    vector<string> res(nRows);
    int idx = 0, d = 1;
    for(auto& c : s){
      res[idx] += c;
      idx += d;
      if(idx == -1)
        idx = 1, d = 1;
      else if(idx == nRows)
        idx = nRows-2, d = -1;
    }
    string fin;
    for(auto& r : res)
      fin += r;
    return fin;
  }
};

int main(){
  auto sol = Solution();
  cout << sol.convert("PAYPALISHIRING", 3);
}
