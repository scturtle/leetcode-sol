class Solution(object):
    def generate(self, n):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        ans = []
        for i in xrange(n):
            l = [1]
            for j in xrange(1, i):
                l.append(ans[-1][j-1] + ans[-1][j])
            if i:
                l.append(1)
            ans.append(l)
        return ans
