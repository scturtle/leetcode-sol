class Solution(object):
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        l, r = 0, n
        while l+1!=r:
            m = (l+r) / 2
            if nums[m] > nums[0]:
                l = m
            else:
                r = m
        if r == n:
            return nums[0]
        return nums[r]
