class Solution(object):
    def summaryRanges(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        res = []
        for n in nums:
            if res and res[-1][1] + 1 == n:
                res[-1][1] += 1
            else:
                res.append([n, n])
        return [("{}->{}".format(i, j) if i != j else str(i))
                for i, j in res]
