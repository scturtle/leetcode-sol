class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if not head:
            return None
        p = head
        n = 0
        vals = []
        while p:
            vals.append(p.val)
            p = p.next
            n += 1
        k = k % n
        vals = vals[-k:] + vals[:-k]
        vals.reverse()
        p = head
        while p:
            p.val = vals.pop()
            p = p.next
        return head
