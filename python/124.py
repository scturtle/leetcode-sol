class Solution(object):
    def _max(self, root):
        if not root:
            return 0, 0
        if root.left == root.right == None:
            return root.val, root.val

        l1, l2 = self._max(root.left)
        l1 = max(l1, 0)
        r1, r2 = self._max(root.right)
        r1 = max(r1, 0)
        if root.left is None:
            return root.val + r1, max(r2, root.val + r1)
        elif root.right is None:
            return root.val + l1, max(l2, root.val + l1)
        else:
            return root.val + max(l1, r1), max(max(l2, r2), l1 + root.val + r1)

    def maxPathSum(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        return self._max(root)[1]
