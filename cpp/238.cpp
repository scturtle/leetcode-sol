#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> left{1}, right{1};
    for(int i=0; i<n; i++){
      left.push_back(nums[i] * left.back());
      right.push_back(nums[n-i-1] * right.back());
    }
    vector<int> res;
    for(int i=0; i<n; i++)
      res.push_back(left[i] * right[n-i-1]);
    return res;
  }
};
