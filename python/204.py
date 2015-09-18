xrange = range


class Solution(object):
    def countPrimes(self, n):
        """
        :type n: int
        :rtype: int
        """
        isprime = [True] * n
        # isprime[0] = isprime[1] = False
        for i in xrange(2, int(n ** 0.5) + 1):
            if isprime[i]:
                for j in xrange(i*i, n, i):
                    isprime[j] = False
        return sum(isprime[2:])
