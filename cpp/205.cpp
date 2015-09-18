#include <map>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  bool isIsomorphic(string s, string t) {
    int n = s.length();
    int v1[n];
    int v2[n];
    map<char, int> m1, m2;
    int cnt1 = 0, cnt2 = 0;
    for(int i=0; i<n; i++){
      char c = s[i];
      if(m1[c] == 0)
        m1[c] = ++cnt1;
      v1[i] = m1[c];
      c = t[i];
      if(m2[c] == 0)
        m2[c] = ++cnt2;
      v2[i] = m2[c];
    }
    for(int i=0; i<n; i++)
      if(v1[i] != v2[i])
        return false;
    return true;
  }
};
