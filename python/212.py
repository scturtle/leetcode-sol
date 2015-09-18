class Solution(object):
    def findWords(self, board, words):
        n = len(board)
        if not n:
            return []
        m = len(board[0])
        if not m:
            return []
        # create trie
        root = {}
        for i, w in enumerate(words):
            p = root
            for c in w:
                if c not in p:
                    p[c] = {}
                p = p[c]
            p[True] = i
        # dfs
        ans = set()
        for i in range(n):
            for j in range(m):
                if board[i][j] in root:
                    t = board[i][j]
                    board[i][j] = None
                    self.dfs(board, i, j, root[t], ans)
                    board[i][j] = t
        return [words[i] for i in ans]

    def dfs(self, board, i, j, p, ans):
        if True in p:
            ans.add(p[True])
        n, m = len(board), len(board[0])
        for ai, aj in ((0, 1), (1, 0), (0, -1), (-1, 0)):
            ii, jj = i+ai, j+aj
            if 0 <= ii < n and 0 <= jj < m and board[ii][jj] in p:
                t = board[ii][jj]
                board[ii][jj] = None
                self.dfs(board, ii, jj, p[t], ans)
                board[ii][jj] = t

s = Solution()
print(s.findWords(['a', 'a'], [['aa']]))
