class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        h = ListNode(None)
        h.next = head
        p = h
        while p and p.next and p.next.next:
            a = p.next
            p.next = a.next
            r = a.next.next
            a.next.next = a
            a.next = r
            p = a
        return h.next
