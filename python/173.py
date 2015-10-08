class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class BSTIterator(object):
    def __init__(self, root):
        """
        :type root: TreeNode
        """
        self.parents = []
        self.p = root
        while self.p and self.p.left:
            self.parents.append(self.p)
            self.p = self.p.left

    def hasNext(self):
        """
        :rtype: bool
        """
        return self.p is not None

    def next(self):
        """
        :rtype: int
        """
        val = self.p.val
        if self.p.right:
            self.p = self.p.right
            while self.p.left:
                self.parents.append(self.p)
                self.p = self.p.left
        else:
            if self.parents:
                self.p = self.parents.pop()
            else:
                self.p = None
        return val

    # def next(self):  # not good as above!
    #     """
    #     :rtype: int
    #     """
    #     val = self.p.val
    #     if self.p.right:
    #         self.parents.append(self.p)  # not necessary!
    #         self.p = self.p.right
    #         while self.p.left:
    #             print('left')
    #             self.parents.append(self.p)
    #             self.p = self.p.left
    #     else:
    #         while self.p == self.parents[-1].right:  # not necessary!
    #             self.p = self.parents[-1].pop()
    #         if not self.parents:
    #             self.p = None
    #         else:
    #             self.p = self.parents[-1].pop()
    #     return val

# Your BSTIterator will be called like this:
root = TreeNode(2)
root.left = TreeNode(1)
root.right = TreeNode(3)
i, v = BSTIterator(root), []
while i.hasNext(): v.append(i.next())
