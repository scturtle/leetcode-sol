class Solution(object):
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        if n < 0:
            x, n = 1.0/x, -n
        ans, t = 1, x
        while n:
            if n & 1:
                ans = ans * t
            n //= 2
            t = t * t
        return ans
