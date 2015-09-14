class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def kth(self, root, k):
        if root.left:
            lcnt, lval = self.kth(root.left, k)
        else:
            lcnt, lval = 0, None
        if root.right:
            rcnt, rval = self.kth(root.right, k-lcnt-1)
        else:
            rcnt, rval = 0, None
        total = lcnt + rcnt + 1
        if k <= lcnt:
            return total, lval
        elif lcnt+1 == k:
            return total, root.val
        else:
            return total, rval

    def kthSmallest(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """
        return self.kth(root, k)[1]
