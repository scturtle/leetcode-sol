class Solution(object):
    def gameOfLife(self, board):
        """
        :type board: List[List[int]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        n = len(board)
        if not n:
            return
        m = len(board[0])
        if not m:
            return
        def nb(i, j):
            ans = 0
            for ai, aj in itertools.product(range(-1, 2), range(-1, 2)):
                if ai == aj == 0 or not(0 <= i+ai < n) or not(0 <= j+aj < m):
                    continue
                ans += board[i+ai][j+aj]
            return ans
        lastlast = last = None
        for i in xrange(n+2):
            cur = []
            if i < n:
                for j in xrange(m):
                    nbs = nb(i, j)
                    if board[i][j] == 1:
                        cur.append(0 if nbs < 2 or nbs > 3 else 1)
                    else:
                        cur.append(1 if nbs == 3 else 0)
            if lastlast:
                for j in xrange(m):
                    board[i-2][j] = lastlast[j]
            lastlast = last
            last = cur
