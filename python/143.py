class Solution(object):
    def reorderList(self, head):
        """
        :type head: ListNode
        :rtype: void Do not return anything, modify head in-place instead.
        """
        vals = []
        p = head
        while p:
            vals.append(p.val)
            p = p.next
        n = len(vals)
        vals[::2], vals[1::2] = vals[:(n+1)/2], vals[(n+1)/2:][::-1]
        vals.reverse()
        p = head
        while p:
            p.val = vals.pop()
            p = p.next
