class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        x = 0
        for n in nums:
            x ^= n
        x = x & (~x+1)
        y1 = y2 = 0
        for n in nums:
            if n & x:
                y1 ^= n
            else:
                y2 ^= n
        return y1, y2
