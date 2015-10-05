class Solution(object):
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums = set(nums)
        ans = 0
        for n in nums:
            if n+1 not in nums:
                c = 0
                while n in nums:
                    c += 1
                    n -= 1
                ans = max(ans, c)
        return ans
