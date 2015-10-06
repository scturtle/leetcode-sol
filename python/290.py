class Solution(object):
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        saw = {}
        pis = [saw.setdefault(c, len(saw)) for c in pattern]
        saw.clear()
        wis = [saw.setdefault(w, len(saw)) for w in str.split()]
        return pis == wis
