class Solution(object):
    def solve(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        n = len(board)
        if not n:
            return
        m = len(board[0])
        saw = set()
        for i, j in itertools.product(range(n), range(m)):
            if board[i][j] == 'X':
                continue
            if(i, j) in saw:
                continue
            ok = True
            can = []
            q = [(i, j)]
            while q:
                i, j = q.pop()
                if (i, j) in saw:
                    continue
                if i < 0 or i >= n or j < 0 or j >= m:
                    ok = False
                    continue
                if board[i][j] == 'X':
                    continue
                can.append((i, j))
                saw.add((i, j))
                for di, dj in ((0, 1), (1, 0), (0, -1), (-1, 0)):
                    q.append((i+di, j+dj))
            if ok:
                for i, j in can:
                    board[i][j] = 'X'
