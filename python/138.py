class Solution(object):
    def copyRandomList(self, head, cache=None):
        """
        :type head: RandomListNode
        :rtype: RandomListNode
        """
        if head is None:
            return None
        if cache is None:
            cache = {}
        if id(head) not in cache:
            new = RandomListNode(head.label)
            cache[id(head)] = new
            new.next = self.copyRandomList(head.next, cache)
            new.random = self.copyRandomList(head.random, cache)
        return cache[id(head)]
