fact = [1]
for i in xrange(1, 201):
    fact.append(fact[-1] * i)

class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        return fact[m+n-2]/fact[m-1]/fact[n-1]
