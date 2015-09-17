def get_nxt(p):
    m = len(p)
    nxt = [None] * (m + 1)
    i, j = 0, -1
    nxt[0] = -1  # trick in backtracing
    while i < m:
        if j == -1 or p[i] == p[j]:
            # expand previous nxt
            i += 1
            j += 1
            nxt[i] = j
        else:
            j = nxt[j]
    return nxt

class Solution(object):
    def shortestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        n = get_nxt(s + '#' + s[::-1])[-1]
        return s[n:][::-1] + s

sol = Solution()
print(sol.shortestPalindrome('aaad'))
