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
  vector<string> generateParenthesis(int n) {
    vector<string> ans;
    if(!n) return ans;
    vector<set<string>> d = {{""}, {"()"}};
    for(int i=2; i<=n; i++){
      set<string> c;
      for(auto& s : d[i-1])
        c.insert("(" + s + ")");
      for(int l=1; l<i; l++){
        int r = i-l;
        for(auto& sl : d[l])
          for(auto& sr : d[r])
            c.insert(sl + sr);
      }
      d.push_back(c);
    }
    for(auto& s : d[n])
      ans.push_back(s);
    return ans;
  }
};

int main(){
  auto sol = Solution();
  for(auto& s : sol.generateParenthesis(3))
    cout << s << endl;
}
