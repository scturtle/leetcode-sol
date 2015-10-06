class Point(object):
    def __init__(self, a=0, b=0):
        self.x = a
        self.y = b


class Solution(object):
    def maxPoints(self, points):
        """
        :type points: List[Point]
        :rtype: int
        """
        if not points:
            return 0
        from fractions import gcd
        maxcnt = 0
        n = len(points)
        for i in xrange(n):
            dup = 0
            cnt = collections.defaultdict(int)
            for j in xrange(n):
                if (points[i].x, points[i].y) == (points[j].x, points[j].y):
                    dup += 1
                    continue
                dy = points[i].y - points[j].y
                dx = points[i].x - points[j].x
                if dx == 0:
                    cnt[()] += 1
                else:
                    t = gcd(dy, dx)
                    dy, dx = dy/t, dx/t
                    cnt[(dy, dx)] += 1
            maxcnt = max(maxcnt, dup + (0 if not cnt else max(cnt.values())))
        return maxcnt


import collections
xrange = range
print(Solution().maxPoints([Point(), Point(), Point(0, 1)]))
