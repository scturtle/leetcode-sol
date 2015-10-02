class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        p = head
        ln = 0
        while p:
            ln += 1
            p = p.next

        k = ln - n
        h = ListNode(None)
        h.next = head
        p = h
        while k:
            k -= 1
            p = p.next
        p.next = p.next.next
        return h.next
