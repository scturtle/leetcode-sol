class Solution(object):
    @staticmethod
    def sort(nums):
        if not nums or len(nums) == 1:
            return nums
        return Solution.sort([n for n in nums if n+nums[0] > nums[0]+n]) +\
               [n for n in nums if n+nums[0] == nums[0]+n] +\
               Solution.sort([n for n in nums if n+nums[0] < nums[0]+n])

    def largestNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        nums = map(str, nums)
        nums = self.sort(nums)
        res = ''.join(nums)
        return '0' if res[0] == '0' else res
