class Solution(object):
    def maxProfit(self, k, prices):
        """
        :type k: int
        :type prices: List[int]
        :rtype: int
        """
        if not prices or not k:
            return 0
        if k >= len(prices)/2:
            ans = 0
            for i in xrange(1, len(prices)):
                ans += max(0, prices[i] - prices[i-1])
            return ans
        mxs = [0] * k
        mis = [-prices[0]] * k
        #print(prices[0], mis, mxs)
        for p in prices[1:]:
            newmxs = []
            for i in xrange(k):
                newmxs.append(max(mxs[i], mis[i] + p))
            for i in xrange(1, k):
                mis[i] = max(mis[i], mxs[i-1] - p)
            mis[0] = max(mis[0], -p)
            mxs = newmxs
            #print(p, mis, mxs)
        return max(mxs)
