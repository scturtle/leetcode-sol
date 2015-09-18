xrange = range

class Solution(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        n = len(grid)
        if n == 0:
            return 0
        m = len(grid[0])
        for i in xrange(n):
            grid[i] = list(grid[i])
        ans = 0
        for i in xrange(n):
            for j in xrange(m):
                if grid[i][j] == '1':
                    ans += 1
                    grid[i][j] = '0'
                    s = [(i, j)]
                    while s:
                        ui, uj = s.pop()
                        for ai, aj in ((0, 1), (1, 0), (0, -1), (-1, 0)):
                            vi, vj = ui+ai, uj+aj
                            if 0<=vi<n and 0<=vj<m and grid[vi][vj] == '1':
                                grid[vi][vj] = '0'
                                s.append((vi, vj))
        return ans

