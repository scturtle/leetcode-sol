class Solution(object):
    def partition(self, head, x):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        """
        left = ListNode(None)
        right = ListNode(None)
        l, r = left, right
        p = head
        while p:
            if p.val < x:
                l.next = p
                l = p
            else:
                r.next = p
                r = p
            p = p.next
        r.next = None
        l.next = right.next
        return left.next
