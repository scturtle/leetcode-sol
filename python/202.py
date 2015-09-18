class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        saw = set()
        while n not in saw:
            if n == 1:
                return True
            saw.add(n)
            n = sum(pow(ord(c)-48, 2) for c in str(n))
        return False
