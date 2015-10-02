class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if not strs:
            return ''
        ln = len(strs[0])
        for s in strs[1:]:
            i = 0
            while i < len(s) and i < ln and s[i] == strs[0][i]:
                i += 1
            ln = min(i, ln)
        return strs[0][:ln]
