class Solution(object):
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        n = len(citations)
        citations.sort(reverse=True)
        if not citations or citations[0] == 0:
            return 0
        if citations[n-1] >= n:
            return n
        l, r = 0, n-1
        while l+1 != r:
            m = (l+r) // 2
            if citations[m] < m+1:
                r = m
            else:
                l = m
        return l+1

sol = Solution()
print(sol.hIndex([1]))
print(sol.hIndex([3, 0, 6, 1, 5]))
