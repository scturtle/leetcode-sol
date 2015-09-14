#include <deque>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    if(k == 0) return {};
    deque<int> q;
    vector<int> v;
    for (int i = 0; i < nums.size(); i++) {
      if (!q.empty() && q.front() <= i - k)
        q.pop_front();
      while (!q.empty() && nums[q.back()] < nums[i])
        q.pop_back();
      q.push_back(i);
      v.push_back(nums[q.front()]);
    }
    return vector<int>(v.begin() + k - 1, v.end());
  }
};

int main(){
  vector<int> v{1,3,-1,-3,5,3,6,7};
  for(int n : Solution().maxSlidingWindow(v, 3))
    cout << n << " ";
  cout << endl;
}
