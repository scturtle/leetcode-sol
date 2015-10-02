class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        n = (-1 if x < 0 else 1) * int(str(abs(x))[::-1])
        return 0 if n < -2147483648 or n > 2147483647 else n
