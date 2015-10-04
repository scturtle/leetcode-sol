class Solution(object):
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        pat = collections.Counter(t)
        l = r = 0
        cnt = 0
        cur = collections.defaultdict(int)
        ans = None

        while l < len(s):
            while r < len(s) and cnt < len(pat):
                cur[s[r]] += 1
                if s[r] in pat and cur[s[r]] == pat[s[r]]:
                    cnt += 1
                r += 1

            # print (l, r, s[l:r], cur)
            if cnt == len(pat):
                while s[l] not in pat or cur[s[l]] > pat[s[l]]:
                    cur[s[l]] -= 1
                    l += 1
                if not ans or len(ans) > r-l:
                    ans = s[l:r]

            cur[s[l]] -= 1
            cnt -= 1
            l += 1

        return '' if ans is None else ans
