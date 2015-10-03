class Solution(object):
    @staticmethod
    def nq(n, idx, cur, ans, col, dia, dib):
        if idx == n:
            ans.append(['.'*i+'Q'+'.'*(n-1-i) for i in cur])
        for q in xrange(n):
            if q not in col and q+idx not in dia and q-idx not in dib:
                col.add(q); dia.add(q+idx); dib.add(q-idx)
                cur.append(q)
                Solution.nq(n, idx+1, cur, ans, col, dia, dib)
                cur.pop()
                col.remove(q); dia.remove(q+idx); dib.remove(q-idx)


    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        ans = []
        Solution.nq(n, 0, [], ans, set(), set(), set())
        return ans
