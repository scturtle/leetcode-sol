class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        if not nums or target < nums[0]:
            return [-1, -1]

        n = len(nums)
        # nums[l] <= target < nums[r]
        l, r = 0, n
        while l+1 < r:
            m = (l+r) / 2
            if nums[m] <= target:
                l = m
            else:
                r = m

        if l == n or nums[l] != target:
            return [-1, -1]
        right = r = l
        if nums[0] == target:
            return [0, r]
        l = 0

        # nums[l] < target <= nums[r]
        while l+1 < r:
            m = (l+r) / 2
            if nums[m] < target:
                l = m
            else:
                r = m
        return [r, right]
