class Solution(object):
    def grayCode(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        if n == 0:
            return [0]
        r = self.grayCode(n-1)
        return r + [(1<<(n-1))+i for i in r[::-1]]
