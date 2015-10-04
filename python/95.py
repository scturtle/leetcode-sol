class Solution(object):
    def generateTrees(self, n, start=1):
        """
        :type n: int
        :rtype: List[TreeNode]
        """
        if not n:
            return [None]

        ans = []
        for l in xrange(n):
            r = n-1-l
            for lt in self.generateTrees(l, start):
                for rt in self.generateTrees(r, start+l+1):
                    t = TreeNode(start+l)
                    t.left = lt
                    t.right = rt
                    ans.append(t)
        return ans
