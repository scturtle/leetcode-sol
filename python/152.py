class Solution(object):
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        ans = max(nums)
        mi = 0
        mx = 0
        for n in nums:
            if n == 0:
                mi = mx = 0
            elif n > 0:
                mi = mi * n
                mx = mx * n if mx else n
                ans = max(ans, mx)
            else:
                mi, mx = min(mx * n, n), mi * n
                ans = max(ans, mx) if mx else ans
        return ans
