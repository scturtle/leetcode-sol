# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def binaryTreePaths(self, root):
        """
        :type root: TreeNode
        :rtype: List[str]
        """
        if root is None:
            return []
        if root.left is None and root.right is None:
            return [str(root.val)]
        return [str(root.val)+"->"+p for p in self.binaryTreePaths(root.left)]+\
               [str(root.val)+"->"+p for p in self.binaryTreePaths(root.right)]
