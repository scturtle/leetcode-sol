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
  string largestNumber(vector<int> &num) {
    vector<string> v;
    for(int n : num)
      v.push_back(to_string(n));
    sort(v.begin(), v.end(), [](string &a, string &b){
        return a+b > b+a;
      });
    // for(string &s : v) cout << s << endl;
    // reverse(v.begin(), v.end());
    string ans;
    for(string &s : v)
      ans += s;
    if(ans[0] == '0') return "0";
    return ans;
  }
};

int main(){
  auto sol = Solution();
  vector<int> v = {128, 12};
  cout << sol.largestNumber(v);
}
