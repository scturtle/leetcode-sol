class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        nodes = []
        while head:
            nodes.append(head)
            head = head.next
        for i in xrange(0, len(nodes) - k + 1, k):
            nodes[i:i + k] = nodes[i:i + k][::-1]
        h = ListNode(None)
        p = h
        for nd in nodes:
            p.next = nd
            p = nd
        p.next = None
        return h.next
