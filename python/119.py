class Solution(object):
    def getRow(self, n):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        last = []
        for i in xrange(1+n):
            l = [1]
            for j in xrange(1, i):
                l.append(last[j-1] + last[j])
            if i:
                l.append(1)
            last = l
        return last
