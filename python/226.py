class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def invertTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        if root is None:
            return None
        t = TreeNode(root.val)
        t.left = self.invertTree(root.right)
        t.right = self.invertTree(root.left)
        return t
