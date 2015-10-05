class Solution(object):
    def connect(self, root):
        """
        :type root: TreeLinkNode
        :rtype: nothing
        """
        if not root:
            return
        chl = None
        while root:
            chl = chl or root.left or root.right
            nxt = root.next
            while nxt and not nxt.left and not nxt.right:
                nxt = nxt.next
            if root.left:
                root.left.next = root.right or (nxt.left or nxt.right if nxt else None)
            if root.right:
                root.right.next = nxt.left or nxt.right if nxt else None
            root = nxt
        self.connect(chl)
