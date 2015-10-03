class Interval(object):
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e


class Solution(object):
    def insert(self, its, newit):
        """
        :type intervals: List[Interval]
        :type newInterval: Interval
        :rtype: List[Interval]
        """
        before = [it for it in its if it.end < newit.start]
        overlapped = [it for it in its if not (it.end < newit.start or
                                               newit.end < it.start)] + [newit]
        after = [it for it in its if newit.end < it.start]
        newit.start = min(it.start for it in overlapped)
        newit.end = max(it.end for it in overlapped)
        return before + [newit] + after
