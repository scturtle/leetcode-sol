class Solution(object):
    def convertToTitle(self, n):
        """
        :type n: int
        :rtype: str
        """
        ans = ''
        while n:
            b = n % 26
            n = n / 26
            if b == 0:
                n -= 1
                b += 26
            ans = chr(ord('A')-1+b) + ans
        return ans
