class Solution(object):
    @staticmethod
    def search(board, word, idx, i, j, vit):
        if idx == len(word):
            return True
        if i < 0 or i >= len(board) or\
           j < 0 or j >= len(board[0]) or\
           board[i][j] != word[idx]:
            return False
        vit.add((i, j))
        for di, dj in ((1, 0), (0, 1), (-1, 0), (0, -1)):
            ni, nj = i+di, j+dj
            if (ni, nj) not in vit:
                if Solution.search(board, word, idx+1, ni, nj, vit):
                    return True
        vit.remove((i, j))
        return False

    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        n = len(board)
        if not n:
            return False
        m = len(board[0])
        if not m:
            return False
        vit = set()
        for i, j in itertools.product(range(n), range(m)):
            if board[i][j] == word[0]:
                if Solution.search(board, word, 0, i, j, vit):
                    return True
        return False
