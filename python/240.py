import bisect


class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        if not matrix:
            return False
        j = bisect.bisect_left(matrix[0], target)
        j = min(len(matrix[0]) - 1, j)
        if matrix[0][j] == target:
            return True
        i = 1
        while i < len(matrix):
            if matrix[i][j] < target:
                while matrix[i][j] < target and j+1 < len(matrix[0]):
                    j += 1
            elif matrix[i][j] > target:
                while matrix[i][j] > target and j > 0:
                    j -= 1
            if matrix[i][j] == target:
                return True
            i += 1
        return False

sol = Solution()
print(sol.searchMatrix([[1, 4], [2, 5]], 2))
