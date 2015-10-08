class MinStack(object):
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.mins = []
        self.stack = []

    def push(self, x):
        """
        :type x: int
        :rtype: nothing
        """
        self.stack.append(x)
        if not self.mins or x <= self.mins[-1]:
            self.mins.append(x)

    def pop(self):
        """
        :rtype: nothing
        """
        v = self.stack.pop()
        if self.mins and self.mins[-1] == v:
            self.mins.pop()

    def top(self):
        """
        :rtype: int
        """
        return self.stack[-1]

    def getMin(self):
        """
        :rtype: int
        """
        return self.mins[-1]
