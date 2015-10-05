class Solution(object):
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: List[List[int]]
        """
        if root is None:
            return []
        if root.left is None and root.right is None:
            return [[root.val]] if root.val == sum else []
        return [[root.val] + p for p in self.pathSum(root.left, sum-root.val)] +\
               [[root.val] + p for p in self.pathSum(root.right, sum-root.val)]
