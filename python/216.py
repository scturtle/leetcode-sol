class Solution(object):

    def dfs(self, k, n, i, cur, res):
        if n == 0 and k == 0:
            res.append(cur[:])
            return
        if k < 0 or n < 0 or i > 9:
            return
        cur.append(i)
        self.dfs(k-1, n-i, i+1, cur, res)
        cur.pop()
        self.dfs(k, n, i+1, cur, res)

    def combinationSum3(self, k, n):
        """
        :type k: int
        :type n: int
        :rtype: List[List[int]]
        """
        res = []
        self.dfs(k, n, 1, [], res)
        return res

print(Solution().combinationSum3(3, 15))
