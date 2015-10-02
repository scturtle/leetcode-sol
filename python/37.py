import itertools


class Solution(object):
    digits = set('123456789')

    @staticmethod
    def dfs(board):
        for i, j in itertools.product(range(9), range(9)):
            if board[i][j] == '.':
                break
        else:
            return True
        saw = board[i] + [board[k][j] for k in range(9)]
        si, sj = i/3*3, j/3*3
        for ai, aj in itertools.product(range(3), range(3)):
            saw.append(board[si+ai][sj+aj])
        allowed = Solution.digits - set(saw)
        for d in allowed:
            board[i][j] = d
            if Solution.dfs(board):
                return True
        board[i][j] = '.'
        return False

    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        Solution.dfs(board)
