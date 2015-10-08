class Solution(object):
    def findPeakElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        l, r = -1, n
        while 1:
            m = (l+r)//2
            left = -float('inf') if m-1 < 0 else nums[m-1]
            right = -float('inf') if m+1 >= n else nums[m+1]
            if left < nums[m] > right:
                return m
            elif left > nums[m]:
                r = m
            else:
                l = m
