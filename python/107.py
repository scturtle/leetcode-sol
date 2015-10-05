class Solution(object):
    def levelOrderBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        ans = []
        cur = [root]
        while cur:
            lev = []
            nxt = []
            for r in cur:
                if r:
                    lev.append(r.val)
                    nxt.append(r.left)
                    nxt.append(r.right)
            if lev:
                ans.append(lev)
            cur = nxt
        ans.reverse()
        return ans
