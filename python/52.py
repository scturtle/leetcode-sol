class Solution(object):
    @staticmethod
    def nq(n, idx, ans, col, dia, dib):
        if idx == n:
            ans[0] += 1
        for q in xrange(n):
            if q not in col and q+idx not in dia and q-idx not in dib:
                col.add(q); dia.add(q+idx); dib.add(q-idx)
                Solution.nq(n, idx+1, ans, col, dia, dib)
                col.remove(q); dia.remove(q+idx); dib.remove(q-idx)

    def totalNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        ans = [0]
        Solution.nq(n, 0, ans, set(), set(), set())
        return ans[0]
