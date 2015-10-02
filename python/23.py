class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    @staticmethod
    def merge2(a, b):
        h = ListNode(None)
        p = h
        while a and b:
            if a.val > b.val:
                a, b = b, a
            p.next = a
            p = a
            a = a.next
        p.next = a or b
        return h.next

    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        if not lists:
            return None
        n = len(lists)
        if n == 1:
            return lists[0]

        l = [Solution.merge2(lists[i], lists[i + 1])
             for i in xrange(0, n - 1, 2)]
        if n & 1:
            l.append(lists[-1])
        return self.mergeKLists(l)
