class Solution {
public:
  bool isAnagram(string s, string t) {
    int cnt_s[26];
    int cnt_t[26];
    for(int i=0; i<26; i++)
      cnt_s[i] = cnt_t[i] = 0;
    int base = int('a');
    for(char c : s) ++cnt_s[int(c)-base];
    for(char c : t) ++cnt_t[int(c)-base];
    for(int i=0; i<26; i++)
      if(cnt_s[i] != cnt_t[i])
        return false;
    return true;
  }
};
