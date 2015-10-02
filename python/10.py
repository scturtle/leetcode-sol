class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        import re
        m = re.match(p, s)
        return m is not None and m.span()[1] == len(s)
