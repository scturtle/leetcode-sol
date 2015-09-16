class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def countNodes(self, root):
        lc = 0
        t = root
        while t:
            lc += 1
            t = t.left
        rc = 0
        t = root
        while t:
            rc += 1
            t = t.right
        if lc == rc:
            return 2**lc - 1
        else:
            return 1 + self.countNodes(root.left) + self.countNodes(root.right)
