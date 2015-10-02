import itertools


class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        s = '1'
        for i in range(n-1):
            s = ''.join(str(len(list(v))) + str(k) for k, v in itertools.groupby(s))
        return s
