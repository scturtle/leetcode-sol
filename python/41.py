class Solution(object):
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.append(-1)
        n = len(nums)
        for i in range(n):
            if nums[i] != i:
                while 0 < nums[i] < n:
                    j = nums[i]
                    if nums[i] == nums[j]:
                        break
                    nums[i], nums[j] = nums[j], nums[i]
        for i in range(1, n):
            if nums[i] != i:
                return i
        return n
