xrange = range


class Solution(object):
    @staticmethod
    def helper(l):
        n = len(l)
        s = []
        rb = [None] * n
        for i in xrange(n):
            while s and l[s[-1]] > l[i]:
                rb[s.pop()] = i
            s.append(i)
        while s:
            rb[s.pop()] = n
        lb = [None] * n
        for i in xrange(n-1, -1, -1):
            while s and l[s[-1]] > l[i]:
                lb[s.pop()] = i
            s.append(i)
        while s:
            lb[s.pop()] = -1
        return max(min(rb[i]-lb[i]-1, l[i])**2 for i in xrange(n))

    def maximalSquare(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        n = len(matrix)
        if not n:
            return 0
        m = len(matrix[0])
        l = [0] * m
        ans = 0
        for i in xrange(n):
            for j in xrange(m):
                l[j] = 0 if matrix[i][j] == '0' else l[j] + 1
            ans = max(ans, self.helper(l))
        return ans
