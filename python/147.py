class Solution(object):
    def insertionSortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        vals = []
        p = head
        while p:
            vals.append(p.val)
            p = p.next
        vals.sort(reverse=True)
        p = head
        while p:
            p.val = vals.pop()
            p = p.next
        return head
