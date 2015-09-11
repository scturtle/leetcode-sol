#include <vector>
using namespace std;

class Solution {
public:
  int missingNumber(vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      while (nums[i] != i) {
        int j = nums[i];
        if (j == n)
          break;
        int t = nums[j];
        nums[j] = nums[i];
        nums[i] = t;
      }
    }
    for (int i = 0; i < n; i++)
      if (nums[i] != i)
        return i;
    return n;
  }
};
