class Solution(object):
    def _flatten(self, root, end):
        if not root:
            return end
        root.right = self._flatten(root.left, self._flatten(root.right, end))
        root.left = None
        return root

    def flatten(self, root, end=None):
        """
        :type root: TreeNode
        :rtype: void Do not return anything, modify root in-place instead.
        """
        self._flatten(root, None)
