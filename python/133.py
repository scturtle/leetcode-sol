class Solution(object):
    def cloneGraph(self, node, cache=None):
        """
        :type node: UndirectedGraphNode
        :rtype: UndirectedGraphNode
        """
        if node is None:
            return None
        if not cache:
            cache = {}
        if id(node) in cache:
            return cache[id(node)]
        newnode = UndirectedGraphNode(node.label)
        cache[id(node)] = newnode
        for nb in node.neighbors:
            newnode.neighbors.append(self.cloneGraph(nb, cache))
        return newnode
