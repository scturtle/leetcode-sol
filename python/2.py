class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        add = 0
        ans = []
        while l1 and l2:
            n = l1.val + l2.val + add
            add = n / 10
            n = n % 10
            ans.append(n)
            l1, l2 = l1.next, l2.next
        l = l1 or l2
        while l:
            n = l.val + add
            add = n / 10
            n = n % 10
            ans.append(n)
            l = l.next
        if add:
            ans.append(add)
        h = ListNode(None)
        p = h
        for n in ans:
            p.next = ListNode(n)
            p = p.next
        return h.next
