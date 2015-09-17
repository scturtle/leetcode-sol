#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

using it = vector<int>::iterator;
class Solution {
  int kth(it bs, it ed, int k){
    if(ed - bs == 1)
      return *bs;
    int v = *(bs + (ed - bs)/2);
    it p = partition(bs, ed, [v](int x){return x > v;});
    partition(p, ed, [v](int x){return x == v;});
    int cnt = p - bs;
    if(k <= cnt)
      return kth(bs, p, k);
    else if(k == cnt+1)
      return(*p);
    else
      return kth(p+1, ed, k-cnt-1);
  }
public:
  int findKthLargest(vector<int>& nums, int k) {
    return kth(nums.begin(), nums.end(), k);
  }
};

int main(){
  vector<int> v{2, 1};
  cout << Solution().findKthLargest(v, 1);
}
