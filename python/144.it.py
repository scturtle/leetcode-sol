class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def preorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        vals = []
        stack = []
        while 1:
            while root:
                vals.append(root.val)
                stack.append(root)
                root = root.left
            if not stack:
                return vals
            root = stack.pop()
            root = root.right
