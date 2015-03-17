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
  int ladderLength(string start, string end, unordered_set<string> &dict) {
    dict.insert(end);
    deque<pair<string, int> > q = {{start, 1}};
    unordered_set<string> saw = {start};
    while(!q.empty()){
      auto t = q.front(); q.pop_front();
      string u = t.first;
      int cnt = t.second;
      if(u == end)
        return cnt;
      for(uint i=0; i<u.length(); i++){
        string st = u.substr(0, i);
        string ed = u.substr(i+1, u.length());
        for(char z : "abcdefghijklmnopqrstuvwxyz"){
          if(z == u[i])
            continue;
          string v = st + z + ed;
          if(saw.find(v) == saw.end() && dict.find(v) != dict.end()){
            saw.insert(v);
            q.push_back({v, cnt+1});
          }
        }
      }
    }
    return 0;
  }
};

int main(){
  auto sol = Solution();
}
