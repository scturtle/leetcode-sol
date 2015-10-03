class Solution(object):
    def uniquePathsWithObstacles(self, grid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
        n = len(grid)
        if not n:
            return 0
        m = len(grid[0])
        if not m:
            return 0
        vals = [0] * m
        last = [0] * m
        if grid[0][0] == 1:
            return 0
        for i in xrange(n):
            for j in xrange(m):
                if i == 0 and j == 0:
                    vals[j] = 1
                    continue
                vals[j] = 0
                if grid[i][j] == 1:
                    continue
                if j:
                    vals[j] += vals[j-1]
                if i:
                    vals[j] += last[j]
            last, vals = vals, last
        return last[-1]
