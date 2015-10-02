class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows < 2:
            return s
        res = [[] for i in xrange(numRows)]
        di = 1
        r = 0
        for c in s:
            res[r].append(c)
            if r == 0:
                di = 1
            elif r == numRows-1:
                di = -1
            r += di
        return ''.join(''.join(row) for row in res)
