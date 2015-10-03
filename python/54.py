class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        m = len(matrix)
        if not m:
            return []
        n = len(matrix[0])
        i = 0
        j = 0
        ans = []
        while m > 1 and n > 1:
            ans.extend(matrix[i][j+k] for k in xrange(n-1))
            j += n-1
            ans.extend(matrix[i+k][j] for k in xrange(m-1))
            i += m-1
            ans.extend(matrix[i][j-k] for k in xrange(n-1))
            j -= n-1
            ans.extend(matrix[i-k][j] for k in xrange(m-1))
            i -= m-1
            i, j, m, n = i+1, j+1, m-2, n-2
        if m == 1:
            ans.extend(matrix[i][j+k] for k in xrange(n))
        elif n == 1:
            ans.extend(matrix[i+k][j] for k in xrange(m))
        return ans
