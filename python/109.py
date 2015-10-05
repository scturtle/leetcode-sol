class Solution(object):
    def sortedListToBST(self, head):
        """
        :type head: ListNode
        :rtype: TreeNode
        """
        if not head:
            return None
        p1 = p2 = p3 = ListNode(None)
        p2.next = head
        while p3 and p3.next:
            p1 = p2
            p2 = p2.next
            p3 = p3.next.next

        t = TreeNode(p2.val)
        p1.next = None
        t.left = self.sortedListToBST(head) if p1.val is not None else None
        t.right = self.sortedListToBST(p2.next)
        return t
