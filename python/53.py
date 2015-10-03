class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        mx = max(nums)
        cur = 0
        for n in nums:
            cur += n
            if cur < 0:
                cur = 0
            else:
                mx = max(mx, cur)
        return mx
