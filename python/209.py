class Solution(object):
    def minSubArrayLen(self, s, nums):
        """
        :type s: int
        :type nums: List[int]
        :rtype: int
        """
        if sum(nums) < s:
            return 0
        n = len(nums)
        mi = n
        i = j = 0
        cur = 0
        while i < n:
            while j < n and cur < s:
                cur += nums[j]
                j += 1
            if cur >= s and j-i < mi:
                print(i, j, cur)
                mi = j-i
            cur -= nums[i]
            i += 1
        return mi

sol = Solution()
print(sol.minSubArrayLen(7, [2,3,1,2,4,3]))
