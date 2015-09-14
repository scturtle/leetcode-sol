# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def dfs(self, root, cur, p, q, res):
        cur.append(root)
        if root == p or root == q:
            res.append(cur[:])
        if root.left:
            self.dfs(root.left, cur, p, q, res)
        if root.right:
            self.dfs(root.right, cur, p, q, res)
        cur.pop()

    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        res = []
        self.dfs(root, [], p, q, res)
        return [i for i, j in zip(res[0], res[1]) if i == j][-1]
