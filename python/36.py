class Solution(object):

    @staticmethod
    def isvalid(l):
        return all(k == '.' or v <= 1 for k, v in collections.Counter(l).items())

    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        cols = list(zip(*board))
        grids = []
        for i in xrange(0, 9, 3):
            for j in xrange(0, 9, 3):
                g = []
                for ii, jj in itertools.product(range(3), range(3)):
                    g.append(board[i+ii][j+jj])
                grids.append(g)
        return all(map(Solution.isvalid, board + cols + grids))
