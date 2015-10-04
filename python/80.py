class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        i = 0
        for j, n in enumerate(nums):
            if i < 2 or nums[i-2] != n:
                nums[i] = n
                i += 1
        return i
