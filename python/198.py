xrange = range

class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        l = [0] * n
        for i in xrange(n):
            l[i] = max(nums[i] + (0 if i <= 1 else l[i-2]),
                       0 if i == 0 else l[i-1])
        return l[-1]

print(Solution().rob([1,1,1,1,1]))
