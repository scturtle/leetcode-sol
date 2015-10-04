class Solution(object):
    def isScramble(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        n = len(s1)
        if n == 0:
            return True
        d = [[[False]*(n+1) for i in range(n)] for j in xrange(n)]
        for i, j in itertools.product(range(n), range(n)):
            d[i][j][1] = s1[i] == s2[j]
        for k in xrange(2, n+1):
            for i, j in itertools.product(range(n-k+1), range(n-k+1)):
                d[i][j][k] = False
                for l in xrange(1, k):
                    r = k-l
                    if (d[i][j][l] and d[i+l][j+l][r]) or (d[i][j+r][l] and d[i+l][j][r]):
                           d[i][j][k] = True
                           break
        return d[0][0][n]
