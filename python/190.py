class Solution(object):
    def reverseBits(self, n):
        """
        :type n: int
        :rtype: int
        """
        return int(bin(n+(1<<32))[2:][:0:-1], 2)
