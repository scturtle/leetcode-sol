#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

using it = vector<int>::iterator;
class Solution {
public:
  int _rob(it st, it ed) {
    int prepre = 0, pre = 0, cur = 0;
    for (; st != ed; ++st) {
      cur = max(*st + prepre, pre);
      prepre = pre;
      pre = cur;
    }
    return cur;
  }
  int rob(vector<int>& nums) {
    int n = nums.size();
    if(n == 0)
      return 0;
    if(n == 1)
      return nums[0];
    if(n == 2)
      return max(nums[0], nums[1]);
    int yes = nums[0] + _rob(nums.begin()+2, nums.end()-1);
    int no = _rob(nums.begin()+1, nums.end());
    return max(yes, no);
  }
};
