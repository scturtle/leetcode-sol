class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        slow = fast = head
        while slow and fast:
            fast = fast.next
            if fast is slow:
                return True
            if fast:
                fast = fast.next
                if fast is slow:
                    return True
            slow = slow.next
        return False
