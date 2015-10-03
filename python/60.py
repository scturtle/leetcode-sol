fact = [1]
for i in xrange(1, 10):
    fact.append(fact[-1] * i)

class Solution(object):
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        digits = range(1, n+1)
        ans = ''
        for i in xrange(n-1, -1, -1):
            c = fact[i]
            d = (k-1)/c
            k -= d * c
            ans += str(digits[d])
            digits.remove(digits[d])
        return ans
