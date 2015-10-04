class Solution(object):
    def recoverTree(self, root):
        """
        :type root: TreeNode
        :rtype: void Do not return anything, modify root in-place instead.
        """
        vals = []
        def inorder(root):
            if not root:
                return
            inorder(root.left)
            vals.append(root.val)
            inorder(root.right)
        inorder(root)
        vals.sort(reverse=True)
        def inorder2(root):
            if not root:
                return
            inorder2(root.left)
            root.val = vals.pop()
            inorder2(root.right)
        inorder2(root)
