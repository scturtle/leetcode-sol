class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        ans = []
        cur = [root]
        nxt = []
        while cur:
            lev = []
            for r in cur:
                if r:
                    lev.append(r.val)
                    nxt.append(r.left)
                    nxt.append(r.right)
            if lev:
                ans.append(lev)
            cur, nxt = nxt, []
        return ans
