class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: Set[str]
        :rtype: bool
        """
        n = len(s)
        can = [False] * (n+1)
        can[0] = True
        for r in xrange(1, n+1):
            for w in wordDict:
                m = len(w)
                if can[r-m] and w == s[r-m:r]:
                    can[r] = True
                    break
        return can[n]
