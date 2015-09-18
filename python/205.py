class Solution(object):
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        d1 = {}
        for i, c in enumerate(s):
            if c not in d1:
                d1[c] = []
            d1[c].append(i)
        d2 = {}
        for i, c in enumerate(t):
            if c not in d1:
                d2[c] = []
            d2[c].append(i)
        return sorted(d1.values()) == sorted(d2.values())
