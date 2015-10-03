class Interval(object):
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e


class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
        intervals.sort(key=lambda it: (it.start, it.end))
        res = []
        for it in intervals:
            if not res or res[-1].end < it.start:
                res.append(it)
            elif res[-1].end < it.end:
                res[-1].end = it.end
        return res
