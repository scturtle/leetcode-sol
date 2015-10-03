class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        return 0 if not s.strip() else len(s.split()[-1])
