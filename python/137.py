class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        twice = 0
        once = 0
        for n in nums:
            twice ^= once & n
            once ^= n
            third = once & twice
            once ^= third
            twice ^= third
        return once
