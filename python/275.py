class Solution(object):
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        n = len(citations)
        if not citations or citations[n-1] == 0:
            return 0
        if citations[0] >= n:
            return n
        l, r = 0, n-1
        while l+1 != r:
            m = (l+r) // 2
            if citations[m] >= n-m:
                r = m
            else:
                l = m
        return n-r

sol = Solution()
print(sol.hIndex([1]))
print(sol.hIndex([0, 1, 3, 5, 6]))
