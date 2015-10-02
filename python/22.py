class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        if n == 0:
            return ['']
        ans = []
        for i in xrange(1, n+1):
            for l in self.generateParenthesis(i-1):
                for r in self.generateParenthesis(n-i):
                    ans.append('(' + l + ')' +r)
        return ans
