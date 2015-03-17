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
  int longestConsecutive(vector<int> &num) {
    unordered_set<int> all(num.begin(), num.end());
    unordered_map<int,int> cnt;
    int ans = 0;
    for(auto v : num){
      if(all.find(v+1) == all.end()){
        vector<int> q = {v};
        while(!q.empty()){
          int t = q.back();
          if(all.find(t-1) == all.end())
            cnt[t] = 1, q.pop_back();
          else if(cnt[t-1] == 0)
            q.push_back(t-1);
          else
            cnt[t] = cnt[t-1]+1, q.pop_back();
        }
        ans = max(ans, cnt[v]);
      }
    }
    return ans;
  }
};

int main(){
  auto sol = Solution();
}
