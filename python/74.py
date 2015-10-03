class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        n = len(matrix)
        if not n or target < matrix[0][0]:
            return False
        l, r = 0, n
        # matrix[l][0] <= target < matrix[r][0]
        while l+1 != r:
            m = (l+r) / 2
            if matrix[m][0] <= target:
                l = m
            else:
                r = m
        if l == n:
            return False

        v = matrix[l]
        l, r = 0, len(v)
        while l+1 != r:
            m = (l+r) / 2
            if v[m] <= target:
                l = m
            else:
                r = m
        return l != len(v) and v[l] == target
