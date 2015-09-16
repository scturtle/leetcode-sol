#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
  bool containsNearbyDuplicate(vector<int> &nums, int k) {
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++) {
      if (i - k - 1 >= 0)
        --m[nums[i - k - 1]];
      if (m[nums[i]])
        return true;
      ++m[nums[i]];
    }
    return false;
  }
};
