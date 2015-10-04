class Solution(object):
    conv = {str(i): i for i in xrange(256)}

    @staticmethod
    def dfs(s, i, cur, ans):
        if len(cur) == 4:
            if i == len(s):
                ans.append('.'.join(map(str, cur)))
            return

        for k in xrange(1, 4):
            t = s[i:i+k]
            if t in Solution.conv:
                cur.append(Solution.conv[t])
                Solution.dfs(s, i+k, cur, ans)
                cur.pop()


    def restoreIpAddresses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        ans = []
        Solution.dfs(s, 0, [], ans)
        return ans
