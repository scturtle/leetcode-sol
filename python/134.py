class Solution(object):
    def canCompleteCircuit(self, gas, cost):
        """
        :type gas: List[int]
        :type cost: List[int]
        :rtype: int
        """
        n = len(gas)
        gas = gas + gas
        cost = cost + cost
        start = 0
        cur = 0
        for i in xrange(n+n):
            cur += gas[i] - cost[i]
            if cur < 0:
                cur = 0
                start = i+1
            else:
                if i+1 - start == n:
                    return start
        return -1
