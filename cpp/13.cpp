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
  int romanToInt(string s) {
    map<char,int> m = {{'M',1000}, {'D',500}, {'C',100},
                       {'L',50}, {'X',10}, {'V',5}, {'I',1}};
    int n = s.length(), ans = 0;
    vector<int> ns;
    for(auto& c : s) ns.push_back(m[c]);
    int i=0;
    while(i < n){
      int j = i+1;
      if(j < n && ns[j] > ns[i])
        ans += ns[j] - ns[i], i = j+1;
      else
        ans += ns[i], ++i;
    }
    return ans;
  }
};

int main(){
  auto sol = Solution();
}
