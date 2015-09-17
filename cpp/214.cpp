#include <string>
#include <algorithm>
using namespace std;

int get_nxt(const char p[], int m) {
  int nxt[m + 1];
  int i = 0, j = -1;
  nxt[0] = -1;
  while (i < m) {
    if (j == -1 || p[i] == p[j])
      ++i, ++j, nxt[i] = j;
    else
      j = nxt[j];
  }
  return nxt[m];
}

class Solution {
public:
  string shortestPalindrome(string s) {
    int n = s.length();
    string t(s);
    t.reserve(2 * n + 1);
    t.push_back('#');
    t.append(s.rbegin(), s.rend());
    int k = get_nxt(t.c_str(), 2 * n + 1);
    string res;
    res.reserve(2 * n - k);
    res.append(s.rbegin(), s.rbegin() + (n - k));
    res.append(s.begin(), s.end());
    return res;
  }
};
