class Solution(object):
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s:
            return 0
        d = set(map(str, range(10, 27)))
        n = len(s)
        ways = [0] * n
        for i in xrange(n):
            if s[i] != '0':
                ways[i] += (ways[i-1] if i else 1)
            if i and s[i-1:i+1] in d:
                ways[i] += (ways[i-2] if i>1 else 1)
        return ways[n-1]
