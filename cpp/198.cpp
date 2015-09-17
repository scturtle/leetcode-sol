#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
  int rob(vector<int> &nums) {
    int prepre = 0, pre = 0, cur = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      cur = max(nums[i] + prepre, pre);
      prepre = pre;
      pre = cur;
    }
    return cur;
  }
};

int main(){
  vector<int> v{1,1,1,1,1};
  cout << Solution().rob(v);
}
