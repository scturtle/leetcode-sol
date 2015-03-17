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
  vector<string> anagrams(vector<string> &strs) {
    map<string, vector<string> > m;
    for(auto &s : strs){
      string ss(s);
      sort(begin(ss), end(ss));
      m[ss].push_back(s);
    }
    vector<string> ans;
    for(auto &t : m)
      if(t.second.size() > 1)
        ans.insert(ans.end(), begin(t.second), end(t.second));
    return ans;
  }
};

int main(){
  auto sol = Solution();
  vector<string> v = {"a"};
  auto ans = sol.anagrams(v);
  for(auto &s : ans)
    cout << s << endl;
}
