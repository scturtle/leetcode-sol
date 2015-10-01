xrange = range


class Solution:
    @staticmethod
    def suffixArray(s):
        n = len(s)
        rkd = {c: i for i, c in enumerate(sorted(set(s)))}
        rank = [rkd[c] for c in s]
        k = 1
        while k <= n:
            xy = [(rank[i], (rank[i + k] if i + k < n else -1))
                  for i in xrange(n)]
            rkd = {c: i for i, c in enumerate(sorted(set(xy)))}
            rank = [rkd[c] for c in xy]
            k *= 2
        sa = [0] * n
        for i in xrange(n):
            sa[rank[i]] = i

        height = [0] * n
        h = 0
        for i in xrange(n):
            if rank[i]:
                if h > 0:
                    h -= 1
                j = sa[rank[i] - 1]
                while i + h < n and j + h < n and s[i + h] == s[j + h]:
                    h += 1
            else:
                h = 0
            height[rank[i]] = h

        return sa, height

    # @return a string
    def longestPalindrome(self, s):
        n = len(s)
        ss = s + '#' + s[::-1]
        sa, height = Solution.suffixArray(ss)
        ln = 0
        # print sa
        # print height
        for i in xrange(1, len(height)):
            l, r = sa[i - 1], sa[i]
            if l > r:
                l, r = r, l
            if l < n and r > n and l + height[i] == 2 * n - r + 1:
                # print i, l, r, height[i], s[l: l+height[i]], (l+height[i])
                if height[i] > ln:
                    ln = height[i]
                    ans = (l, l + ln)
        return s[ans[0]:ans[1]]
