class Solution(object):
    def isValidBST(self, root, l=None, r=None):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not root:
            return True
        if l is not None and l >= root.val:
            return False
        if r is not None and r <= root.val:
            return False
        return self.isValidBST(root.left, l, root.val) and\
               self.isValidBST(root.right, root.val, r)
