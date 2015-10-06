class Solution(object):
    @staticmethod
    def get_dp(s):
        n = len(s)
        dp = [[False] * (n+1) for i in xrange(n)]
        for i in xrange(n):
            dp[i][0] = dp[i][1] = True
        for l in xrange(2, n+1):
            for i in xrange(n-l+1):
                dp[i][l] = s[i] == s[i+l-1] and dp[i+1][l-2]
        return dp

    def partition(self, s):
        """
        :type s: str
        :rtype: List[List[str]]
        """
        n = len(s)
        dp = self.get_dp(s)
        cur = []
        ans = []

        def dfs(i):
            if i == n:
                ans.append(cur[:])
                return
            for j in xrange(i+1, n+1):
                if dp[i][j-i]:
                    cur.append(s[i:j])
                    dfs(j)
                    cur.pop()
        dfs(0)
        return ans
