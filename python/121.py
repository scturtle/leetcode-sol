class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if not prices:
            return 0
        mi = prices[0]
        ans = 0
        for p in prices:
            ans = max(ans, p - mi)
            mi = min(mi, p)
        return ans
