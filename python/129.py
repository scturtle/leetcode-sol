class Solution(object):
    def sumNumbers(self, root, pre=0):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        cur = pre + root.val
        if root.left == root.right == None:
            return cur
        return self.sumNumbers(root.left, 10*cur) + self.sumNumbers(root.right, 10*cur)
