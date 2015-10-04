class Solution(object):
    def isInterleave(self, s1, s2, s3):
        """
        :type s1: str
        :type s2: str
        :type s3: str
        :rtype: bool
        """
        n1, n2, n3 = len(s1), len(s2), len(s3)
        if n1 + n2 != n3:
            return False
        dp = [[False] * (n2+1) for j in xrange(n1+1)]
        for i in xrange(n1+1):
            for j in xrange(n2+1):
                if i == j == 0:
                    dp[0][0] = True
                else:
                    dp[i][j] = (i > 0 and s3[i+j-1] == s1[i-1] and dp[i-1][j]) or\
                               (j > 0 and s3[i+j-1] == s2[j-1] and dp[i][j-1])
        return dp[n1][n2]
