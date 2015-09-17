class Solution(object):
    def _rob(self, nums):
        prepre = pre = cur = 0
        for n in nums:
            cur = max(n + prepre, pre)
            prepre = pre
            pre = cur
        return cur

    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        if n == 0:
            return 0
        elif n == 1:
            return nums[0]
        elif n == 2:
            return max(nums[0], nums[1])
        else:
            # n >= 3
            return max(n[0] + self._rob(nums[2:-1]),
                       self._rob(nums[1:]))
