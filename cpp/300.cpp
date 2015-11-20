#include<vector>
using namespace std;

class Solution {
public:
  int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    if(!n) return 0;
    vector<int> tail(n);
    tail[0] = nums[0];
    int mx = 1;
    for(int num : nums){
      if(num > tail[mx-1])
        tail[mx++] = num;
      else{
        int l = -1, r = mx-1;
        while(l+1 != r){
          int m = (l+r) / 2;
          // tail[l] < num && num <= tail[r]
          if(tail[m] < num)
            l = m;
          else
            r = m;
        }
        tail[r] = num;
      }
    }
    return mx;
  }
};
