import collections


class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        d = collections.defaultdict(int)
        i = 0
        ans = 0
        for j, c in enumerate(s):
            d[c] += 1
            while d[c] > 1:
                d[s[i]] -= 1
                i += 1
            ans = max(ans, j-i+1)
        return ans
