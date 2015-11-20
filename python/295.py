import heapq


class MedianFinder:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.less = []  # max-heap
        self.ln = 0
        self.more = []  # min-heap
        self.mn = 0

    def addNum(self, num):
        """
        Adds a num into the data structure.
        :type num: int
        :rtype: void
        """
        if not self.more or num > self.more[0]:
            heapq.heappush(self.more, num)
            self.mn += 1
        else:
            heapq.heappush(self.less, -num)
            self.ln += 1
        if self.mn - self.ln > 1:
            heapq.heappush(self.less, -heapq.heappop(self.more))
            self.mn -= 1
            self.ln += 1
        elif self.ln - self.mn > 1:
            heapq.heappush(self.more, -heapq.heappop(self.less))
            self.mn += 1
            self.ln -= 1
        assert abs(self.mn - self.ln) <= 1, (self.less, self.more)

    def findMedian(self):
        """
        Returns the median of current data stream
        :rtype: float
        """
        if self.ln == self.mn:
            return (-self.less[0] + self.more[0]) / 2.
        elif self.ln > self.mn:
            return -self.less[0]
        else:
            return self.more[0]


# Your MedianFinder object will be instantiated and called as such:
mf = MedianFinder()
mf.addNum(-1)
print(mf.findMedian())
mf.addNum(-2)
print(mf.findMedian())
mf.addNum(-3)
print(mf.findMedian())
mf.addNum(-4)
print(mf.findMedian())
mf.addNum(-5)
print(mf.findMedian())
