class Solution(object):
    def isSymmetric(self, a, b=None):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if b is None:
            b = a
        if not a and not b:
            return True
        if not a or not b:
            return False
        return a.val == b.val and self.isSymmetric(a.left, b.right) and self.isSymmetric(a.right, b.left)
