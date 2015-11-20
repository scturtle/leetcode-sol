class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        ''' in-order '''
        stack = []
        last = None
        while 1:
            while root:
                stack.append(root)
                root = root.left
            if not stack:
                return True
            root = stack.pop()
            if last is not None and last >= root.val:
                return False
            last = root.val
            root = root.right
