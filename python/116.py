class Solution(object):
    def connect(self, root):
        """
        :type root: TreeLinkNode
        :rtype: nothing
        """
        if root is None or root.left is None:
            return
        nxt = root.left
        while root:
            root.left.next = root.right
            if root.next:
                root.right.next = root.next.left
            root = root.next
        self.connect(nxt)
