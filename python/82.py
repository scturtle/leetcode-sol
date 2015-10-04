class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        h = ListNode(None)
        h.next = head
        p = h
        while p and p.next and p.next.next:
            if p.next.val == p.next.next.val:
                v = p.next.val
                while p.next and p.next.val == v:
                    p.next = p.next.next
            else:
                p = p.next
        return h.next
