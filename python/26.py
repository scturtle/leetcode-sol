class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        i = 0
        last = None
        for n in nums:
            if n != last:
                nums[i] = n
                i += 1
            last = n
        return i
