#include <vector>
using namespace std;

class Solution {
public:
  void moveZeroes(vector<int> &nums) {
    int n = nums.size();
    int i = 0;
    for (int j = 0; j < n; j++)
      if (nums[j])
        nums[i++] = nums[j];
    while (i < n)
      nums[i++] = 0;
  }
};
