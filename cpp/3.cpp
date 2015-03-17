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
    int lengthOfLongestSubstring(string s) {
      unordered_map<char,int> cnt;
      uint res, l, r;
      res = l = r = 0;
      while(l != s.size()){
        while(r!=s.size() && cnt[s[r]] == 0){
          ++cnt[s[r]];
          ++r;
        }
        res = max(res, r-l);
        if(r!=s.size()){
          while(cnt[s[r]]!=0){
            --cnt[s[l]];
            ++l;
          }
        } else return res;
      }
      return res;
    }
};


int main(){
  auto sol = Solution();
}
