import queue as Queue


class Stack(object):
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.q1 = Queue.Queue()
        self.q2 = Queue.Queue()

    def push(self, x):
        """
        :type x: int
        :rtype: nothing
        """
        self.q1.put(x)

    def pop(self):
        """
        :rtype: nothing
        """
        for i in range(self.q1.qsize()-1):
            self.q2.put(self.q1.get())
        self.q1, self.q2 = self.q2, self.q1
        self.q2.get()

    def top(self):
        """
        :rtype: int
        """
        last = None
        for i in range(self.q1.qsize()):
            last = self.q1.get()
            self.q2.put(last)
        self.q1, self.q2 = self.q2, self.q1
        return last

    def empty(self):
        """
        :rtype: bool
        """
        return self.q1.empty()
