class Solution(object):
    cache = []
    def numSquares(self, n):
        """
        :type n: int
        :rtype: int
        """
        cnt = self.cache
        ln = len(cnt)
        cnt.extend(range(ln, n+1))
        for i in xrange(ln, n+1):
            for j in range(1, i+1):
                sq = j*j
                if sq > i:
                    break
                if cnt[i-sq] + 1 < cnt[i]:
                    cnt[i] = cnt[i-sq] + 1
        return cnt[n]

sol = Solution()
print sol.numSquares(7927)

