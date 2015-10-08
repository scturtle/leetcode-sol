class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        m = c = 0
        for n in nums:
            if c == 0:
                m = n
                c = 1
            else:
                c += 1 if m == n else -1
        return m
