#include <map>
#include <vector>
#include <cstdlib>
#include <utility>
using namespace std;

using ll = long long;
class Solution {
public:
  bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
    map<int, vector<pair<int, ll>>> d;
    for (size_t i = 0; i < nums.size(); ++i) {
      int ki = nums[i] / t;
      for (int kj = ki - 1; kj <= ki + 1; ++kj) {
        for (auto &p : d[kj]) {
          int j = p.first;
          ll m = p.second;
          if ((ll)i - j <= k && abs(m - nums[i]) <= t)
            return true;
        }
      }
      d[ki].push_back(make_pair(i, nums[i]));
    }
    return false;
  }
};
