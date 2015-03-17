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

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

bool cmp(const Interval &a, const Interval &b){
  return a.start < b.start || (a.start == b.start && a.end < b.end);
}

class Solution {
public:
  vector<Interval> merge(vector<Interval> &intervals) {
    sort(begin(intervals), end(intervals), cmp);
    vector<Interval> ans;
    for(auto &v : intervals){
      if(ans.empty() || ans.back().end < v.start)
        ans.push_back(v);
      else
        ans.back().end = max(ans.back().end, v.end);
    }
    return ans;
  }
};

int main(){
  auto sol = Solution();
}
