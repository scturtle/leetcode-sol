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

// bool cmp(const Interval &a, const Interval &b){
//   return a.start < b.start || (a.start == b.start && a.end < b.end);
// }

class Solution {
public:
  vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    vector<Interval> ans;
    uint i = 0;
    for(; i<intervals.size() && intervals[i].end < newInterval.start; i++)
      ans.push_back(intervals[i]);
    if(i == intervals.size() || newInterval.end < intervals[i].start)
      ans.push_back(newInterval);
    else {
      int start = min(intervals[i].start, newInterval.start),
        end = max(intervals[i].end, newInterval.end);
      for(; i<intervals.size() && intervals[i].start <= end; i++)
        end = max(end, intervals[i].end);
      ans.push_back(Interval(start, end));
    }
    for(; i<intervals.size(); i++)
      ans.push_back(intervals[i]);
    return ans;
  }
};

int main(){
  auto sol = Solution();
}
