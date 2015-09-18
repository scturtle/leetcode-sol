class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def rightSideView(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if root is None:
            return []
        l = self.rightSideView(root.left)
        r = self.rightSideView(root.right)
        return [root.val] + r + l[len(r):]

t1 = TreeNode(1)
t2 = TreeNode(2)
t1.left = t2
print(Solution().rightSideView(t1))
