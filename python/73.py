class Solution(object):
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        if not n:
            return
        m = len(matrix[0])
        rows, cols = set(), set()
        for i, j in itertools.product(range(n), range(m)):
            if matrix[i][j] == 0:
                rows.add(i)
                cols.add(j)
        for i, j in itertools.product(range(n), range(m)):
            if i in rows or j in cols:
                matrix[i][j] = 0
