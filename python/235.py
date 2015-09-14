class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def search(self, root, node, path):
        path.append(root)
        if root is node:
            return path
        elif node.val < root.val:
            return self.search(root.left, node, path)
        else:
            return self.search(root.right, node, path)

    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        ppath = self.search(root, p, [])
        qpath = self.search(root, q, [])
        return [i for i, j in zip(ppath, qpath) if i == j][-1]
