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
  string convertToTitle(int n) {
    int tmp[7];
    tmp[0] = 0; tmp[1] = 26;
    for(int i=2; i<7; i++)
      tmp[i] = 26 * tmp[i-1];
    string ans;
    for(int i=6; i>0; i--){
      int c = n / tmp[i];
      n %= tmp[i];
      if(c && n <= tmp[i-1])
        --c, n += tmp[i];
      if(c)
        ans += 'A' + c - 1;
    }
    ans += 'A' + n - 1;
    return ans;
  }
};

int main(){
  auto sol = Solution();
  cout << sol.convertToTitle(27);
}
