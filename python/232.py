class Queue(object):
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.f = []
        self.r = []

    def push(self, x):
        """
        :type x: int
        :rtype: nothing
        """
        self.r.append(x)
        if len(self.f) < len(self.r):
            self.f = self.r[::-1] + self.f
            self.r.clear()

    def pop(self):
        """
        :rtype: nothing
        """
        self.f.pop()
        if len(self.f) < len(self.r):
            self.f = self.r[::-1] + self.f
            self.r.clear()

    def peek(self):
        """
        :rtype: int
        """
        return self.f[-1]

    def empty(self):
        """
        :rtype: bool
        """
        return bool(self.f)
