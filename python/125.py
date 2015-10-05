class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        s = [c for c in s.lower() if c.isalnum()]
        return s == s[::-1]
