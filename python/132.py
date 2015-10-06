class Solution(object):
    def minCut(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s:
            return 0
        n = len(s)
        dp = [[False] * (n+1) for i in xrange(n)]
        for i in xrange(n):
            dp[i][0] = dp[i][1] = True
        for l in xrange(2, n+1):
            for i in xrange(n-l+1):
                dp[i][l] = s[i] == s[i+l-1] and dp[i+1][l-2]

        cut = [float('inf')] * (n+1)
        cut[0] = -1
        for i in xrange(1, n+1):
            for j in xrange(i):
                if dp[j][i-j]:
                    cut[i] = min(cut[i], cut[j]+1)
        return cut[n]
