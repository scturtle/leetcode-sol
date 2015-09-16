import heapq
import collections


class Solution(object):
    def getSkyline(self, buildings):
        """
        :type buildings: List[List[int]]
        :rtype: List[List[int]]
        """
        l = []
        for xi, xj, y in buildings:
            l.append((xi, -y))  # higher enter first
            l.append((xj, y))  # lower exit first
        l.sort()
        h = []  # max heap for height
        rm = collections.Counter()
        res = []
        for x, y in l:
            if y < 0:  # enter
                heapq.heappush(h, y)  # min 2 max
            else:  # mark as removed
                rm[y] += 1
            while h and rm[-h[0]]:
                rm[-h[0]] -= 1
                heapq.heappop(h)
            mxh = -h[0] if h else 0
            if not res or res[-1][1] != mxh:
                res.append((x, mxh))
        return res

sol = Solution()
# print(sol.getSkyline([[1, 2, 1], [1, 2, 2], [1, 2, 3]]))
print(sol.getSkyline([[0, 1, 3]]))
