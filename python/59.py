class Solution(object):
    def generateMatrix(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        m = [[-1] * n for i in xrange(n)]
        i = 0
        j = 0
        v = 1
        while m > 1 and n > 1:
            for k in xrange(n-1):
                m[i][j+k] = v+k
            j, v = j+n-1, v+n-1
            for k in xrange(n-1):
                m[i+k][j] = v+k
            i, v = i+n-1, v+n-1
            for k in xrange(n-1):
                m[i][j-k] = v+k
            j, v = j-n+1, v+n-1
            for k in xrange(n-1):
                m[i-k][j] = v+k
            i, v = i-n+1, v+n-1
            i, j, n = i+1, j+1, n-2
        if n == 1:
            m[i][j] = v
        return m
