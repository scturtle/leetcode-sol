class Solution(object):
    def sortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head or not head.next:
            return head

        h = ListNode(None)
        p1 = p2 = h
        h.next = head
        while p2.next and p2.next.next:
            p2 = p2.next.next
            p1 = p1.next
        head2 = p1.next
        p1.next = None

        a, b = self.sortList(head), self.sortList(head2)
        h.next = None
        p = h
        while a and b:
            if a.val > b.val:
                a, b = b, a
            p.next = a
            p = a
            a = a.next
        p.next = a or b
        return h.next
