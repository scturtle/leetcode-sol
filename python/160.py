class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        n1 = n2 = 0
        p = headA
        while p:
            n1 += 1
            p = p.next
        p = headB
        while p:
            n2 += 1
            p = p.next
        if n1 < n2:
            headA, headB, n1, n2 = headB, headA, n2, n1
        p1, p2 = headA, headB
        for i in xrange(n1-n2):
            p1 = p1.next
        while p1 != p2:
            p1 = p1.next
            p2 = p2.next
        return p1
