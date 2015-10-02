class Solution(object):
    @staticmethod
    def get_nxt(needle):
        n = len(needle)
        nxt = [0] * (n+1)
        nxt[0] = -1
        i, j = 0, -1
        while i < n:
            if j == -1 or needle[i] == needle[j]:
                i, j = i+1, j+1
                nxt[i] = j
            else:
                j = nxt[j]
        return nxt

    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        nxt = Solution.get_nxt(needle)
        i = j = 0
        n, m = len(haystack), len(needle)
        if m == 0:
            return 0
        while i < n:
            if j == -1 or haystack[i] == needle[j]:
                i, j = i+1, j+1
                if j == m:
                    return i-j
            else:
                j = nxt[j]
        return -1
