xrange = range

class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: Set[str]
        :rtype: List[str]
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
        if not can[n]:
            return []

        dp = [[] for i in xrange(n+1)]
        dp[n] = [None]
        for i in xrange(n-1, -1, -1):
            if not can[i]:
                continue
            for w in wordDict:
                m = len(w)
                if i+m <= n and dp[i+m] and w == s[i:i+m]:
                    dp[i].append(w)

        ans = []
        cur = []

        def dfs(i):
            for w in dp[i]:
                if w is None:
                    ans.append(' '.join(cur))
                else:
                    cur.append(w)
                    dfs(i+len(w))
                    cur.pop()
        dfs(0)
        return ans

print(Solution().wordBreak('catsanddog', {"cat", "cats", "and", "sand", "dog"}))
