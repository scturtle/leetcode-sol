#include <vector>
using namespace std;

class Solution {
public:
  int calculate(string s) {
    vector<int> vals; vector<char> ops;
    int n = s.size(), i = 0, ans = 0;
    char op = '+';
    while (i < n) {
      char c = s[i];
      if ('0' <= c && c <= '9') {
        int val = 0;
        while (i < n && '0' <= s[i] && s[i] <= '9') {
          val = val * 10 + s[i] - '0'; ++i;
        }
        ans = op == '+' ? ans + val : ans - val;
      } else if (c == '+' || c == '-') {
        op = c; ++i;
      } else if (c == '(') {
        vals.push_back(ans); ops.push_back(op);
        ans = 0; op = '+'; ++i;
      } else if (c == ')') {
        int pre = vals.back(); op = ops.back();
        vals.pop_back(); ops.pop_back();
        ans = op == '+' ? pre + ans : pre - ans;
        ++i;
      } else ++i;
    }
    return ans;
  }
};
