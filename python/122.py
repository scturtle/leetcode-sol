class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        ans = 0
        for i in xrange(1, len(prices)):
            ans += max(0, prices[i] - prices[i-1])
        return ans
