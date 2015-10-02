class Solution(object):
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        dp = [0] * len(s)
        for i in range(1, len(s)):
            if s[i] == ')' and i:
                j = i-dp[i-1]-1
                if j >= 0 and s[j] == '(':
                    dp[i] = dp[i-1] + 2
                    if j:
                        dp[i] += dp[j-1]
        return max(dp) if dp else 0
