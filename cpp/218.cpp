#include <algorithm>
#include <vector>
#include <set>
#include <utility>
using namespace std;

class Solution {
public:
  vector<pair<int, int>> getSkyline(vector<vector<int>> &buildings) {
    vector<pair<int, int>> l;
    for (auto &b : buildings) {
      l.push_back(make_tuple(b[0], -b[2]));
      l.push_back(make_tuple(b[1], b[2]));
    }
    sort(l.begin(), l.end());
    multiset<int> h{0};
    vector<pair<int, int>> res;
    for (auto &t : l) {
      if(t.second < 0)
        h.insert(-t.second);
      else
        h.erase(h.find(t.second));
      int mxh = *(h.rbegin());
        if (res.size() == 0 || res.back().second != mxh)
          res.push_back(make_pair(t.first, mxh));
      }
      return res;
  }
};
