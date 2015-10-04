class Solution(object):
    def numTrees(self, n, cache={0: 1}):
        """
        :type n: int
        :rtype: int
        """
        if n in cache:
            return cache[n]
        ans = 0
        for l in xrange(n):
            r = n-1-l
            ans += self.numTrees(l) * self.numTrees(r)
        cache[n] = ans
        return ans
