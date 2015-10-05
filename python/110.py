class Solution(object):
    @staticmethod
    def _bl(root):
        if root is None:
            return True, 0
        lok, lh = Solution._bl(root.left)
        rok, rh = Solution._bl(root.right)
        return lok and rok and abs(lh-rh) <= 1, 1+max(lh, rh)
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        return Solution._bl(root)[0]
