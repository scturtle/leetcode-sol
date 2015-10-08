class Solution(object):
    def titleToNumber(self, s):
        """
        :type s: str
        :rtype: int
        """
        t = 1
        ans = 0
        for c in s[::-1]:
            ans += (ord(c)-ord('A')+1) * t
            t *= 26
        return ans
