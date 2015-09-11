#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int nthUglyNumber(int n) {
    vector<int> q{1};
    int i2 = 0, i3 = 0, i5 = 0;
    for (int i = 0; i < n - 1; i++) {
      int m2 = 2 * q[i2], m3 = 3 * q[i3], m5 = 5 * q[i5];
      int mi = min(min(m2, m3), m5);
      q.push_back(mi);
      if (mi == m2) ++i2;
      if (mi == m3) ++i3;
      if (mi == m5) ++i5;
    }
    return q.back();
  }
};
