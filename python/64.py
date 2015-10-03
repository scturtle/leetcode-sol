class Solution(object):
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        n = len(grid)
        if not n:
            return 0
        m = len(grid[0])
        for i in xrange(n):
            for j in xrange(m):
                if i and j:
                    grid[i][j] += min(grid[i][j-1], grid[i-1][j])
                elif i:
                    grid[i][j] += grid[i-1][j]
                elif j:
                    grid[i][j] += grid[i][j-1]
        return grid[n-1][m-1]
