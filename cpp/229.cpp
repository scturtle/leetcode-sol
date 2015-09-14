#include <vector>
using namespace std;

class Solution {
public:
  vector<int> majorityElement(vector<int> &nums) {
    int item1, item2, cnt1 = 0, cnt2 = 0;
    for(int n : nums)
      if(cnt1 && n == item1)
        ++cnt1;
      else if(cnt2 && n == item2)
        ++cnt2;
      else if(cnt1 == 0)
        cnt1 = 1, item1 = n;
      else if(cnt2 == 0)
        cnt2 = 1, item2 = n;
      else
        --cnt1, --cnt2;
    cnt1 = cnt2 = 0;
    for(int n : nums)
      if(n == item1) ++cnt1;
      else if(n == item2) ++cnt2;
    vector<int> res;
    if(cnt1 > nums.size() / 3) res.push_back(item1);
    if(cnt2 > nums.size() / 3) res.push_back(item2);
    return res;
  }
};
