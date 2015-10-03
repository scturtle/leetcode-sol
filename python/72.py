class Solution(object):
    def minDistance(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        n1 = len(word1)
        n2 = len(word2)
        vals, last = [0] * (n2+1), range(n2+1)
        for i in xrange(1, n1+1):
            vals[0] = i
            for j in xrange(1, n2+1):
                vals[j] = min([last[j-1]+(0 if word1[i-1]==word2[j-1] else 1),
                               1+vals[j-1], 1+last[j]])
            last, vals = vals, last
        return last[-1]
