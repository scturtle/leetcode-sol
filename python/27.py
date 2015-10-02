class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        i = 0
        for n in nums:
            if n != val:
                nums[i] = n
                i += 1
        return i
