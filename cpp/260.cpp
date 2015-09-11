#include<vector>
using namespace std;

class Solution {
public:
  vector<int> singleNumber(vector<int>& nums) {
    int x = 0;
    for(int n : nums)
      x ^= n;
    x = x & (~x + 1);
    int y1=0, y2=0;
    for(int n : nums)
      if(x ^ n)
        y1 ^= n;
      else
        y2 ^= n;
    return {y1, y2};
  }
};
