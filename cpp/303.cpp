#include <vector>
#include <iostream>
using namespace std;

class NumArray {
  vector<int> s;
public:
  NumArray(vector<int> &nums) {
    int n = nums.size();
    if(n == 0) return;
    s = vector<int>(n+1, 0);
    for(int i=0; i<n; i++)
      s[i+1] = s[i] + nums[i];
  }

  int sumRange(int i, int j) {
    return s[j+1] - s[i];
  }
};
