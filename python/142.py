class Solution(object):
    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        saw = set()
        p = head
        while p:
            if id(p) in saw:
                return p
            saw.add(id(p))
            p = p.next
        return None
