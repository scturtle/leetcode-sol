import collections
xrange = range


class Solution(object):
    def dfs(self, pre, i, finished, saw):
        if i in finished:
            return True
        if i in saw:
            return False
        saw.add(i)
        res = True
        for j in pre[i]:
            res = res and self.dfs(pre, j, finished, saw)
        finished.add(i)
        return res

    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """
        pre = collections.defaultdict(set)
        for u, v in prerequisites:
            pre[u].add(v)
        finished = set()
        saw = set()
        for i in xrange(numCourses):
            if not self.dfs(pre, i, finished, saw):
                return False
        return True
