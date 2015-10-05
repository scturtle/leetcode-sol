class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if not prices:
            return 0
        mi = prices[0]
        mx1 = 0
        mx2 = -prices[0]
        ans = 0
        for p in prices[1:]:
            ans = max(ans, p + mx2)
            mx2 = max(mx2, mx1 - p)
            mx1 = max(mx1, p - mi)
            mi = min(mi, p)
        return ans
