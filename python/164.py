class Solution(object):

    def maximumGap(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        mi, mx = min(nums), max(nums)
        if mi == mx:
            return 0
        m = (mx - mi) / len(nums) + 1
        bn = (mx - mi) / m + 1
        mins, maxs = [None] * bn, [None] * bn
        for n in nums:
            i = (n - mi) / m
            if mins[i] is None or mins[i] > n:
                mins[i] = n
            if maxs[i] is None or maxs[i] < n:
                maxs[i] = n
        ans = 0
        last_max = None
        for i in xrange(bn):
            if mins[i] is not None:
                if last_max is not None:
                    ans = max(ans, mins[i] - last_max)
                last_max = maxs[i]
        return ans
