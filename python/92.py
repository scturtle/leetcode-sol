class Solution(object):
    def reverseBetween(self, head, m, n):
        """
        :type head: ListNode
        :type m: int
        :type n: int
        :rtype: ListNode
        """
        vals = []
        p = head
        while p:
            vals.append(p.val)
            p = p.next
        vals[m-1:n] = vals[m-1:n][::-1]
        vals.reverse()
        p = head
        while p:
            p.val = vals.pop()
            p = p.next
        return head
