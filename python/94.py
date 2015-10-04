class Solution(object):
    def inorderTraversal(self, root, ans=None):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if ans is None:
            ans = []
        if not root:
            return ans
        self.inorderTraversal(root.left, ans)
        ans.append(root.val)
        self.inorderTraversal(root.right, ans)
        return ans
