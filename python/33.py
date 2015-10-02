class Solution(object):
    @staticmethod
    def bs(nums, i, j, target):
        if target < nums[i]:
            return -1
        # nums[i] <= target < nums[j]
        while i+1 < j:
            m = (i + j) / 2
            if nums[m] <= target:
                i = m
            else:
                j = m
        if i < j and nums[i] == target:
            return i
        else:
            return -1

    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        n = len(nums)
        i, j = 0, n
        # nums[i] >= nums[0] && nums[j] < nums[0]
        while i+1 < j:
            m = (i+j) / 2
            if nums[m] >= nums[0]:
                i = m
            else:
                j = m
        if j == n or target >= nums[0]:
            return self.bs(nums, 0, j, target)
        else:
            return self.bs(nums, j, n, target)
