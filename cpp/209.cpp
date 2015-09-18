#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
  int minSubArrayLen(int s, vector<int>& nums) {
    if(accumulate(nums.begin(), nums.end(), 0) < s)
      return 0;
    int n = nums.size();
    int mi = n, cur = 0, i = 0, j = 0;
    while(i < n){
      while(j < n && cur < s)
        cur += nums[j++];
      if(cur >= s && j-i < mi)
        mi = j-i;
      cur -= nums[i++];
    }
    return mi;
  }
};
