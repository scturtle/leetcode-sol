class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        h = ListNode(None)
        p = head
        while p:
            rest = p.next
            p.next = h.next
            h.next = p
            p = rest
        return h.next
