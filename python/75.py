class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        red, blue = 0, n-1
        i = 0
        while i <= blue:
            if nums[i] == 0:
                nums[i] = nums[red]
                nums[red] = 0
                red += 1
                i += 1
            elif nums[i] == 1:
                i += 1
            elif nums[i] == 2:
                nums[i] = nums[blue]
                nums[blue] = 2
                blue -= 1
                # no addvance i
