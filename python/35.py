class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if not nums or target < nums[0]:
            return 0

        n = len(nums)
        l, r = 0, n
        while l+1 != r:
            m = (l+r) / 2
            if nums[m] <= target:
                l = m
            else:
                r = m

        return l if l != n and nums[l] == target else l+1
