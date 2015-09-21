class Iterator(object):
    def __init__(self, nums):
        """
        Initializes an iterator object to the beginning of a list.
        :type nums: List[int]
        """

    def hasNext(self):
        """
        Returns true if the iteration has more elements.
        :rtype: bool
        """

    def next(self):
        """
        Returns the next element in the iteration.
        :rtype: int
        """


class PeekingIterator(object):
    def __init__(self, iterator):
        """
        Initialize your data structure here.
        :type iterator: Iterator
        """
        self.it = iterator
        self.hasnext = self.it.hasNext()
        self.peekval = self.it.next() if self.hasnext else None

    def peek(self):
        """
        Returns the next element in the iteration without advancing the iterator.
        :rtype: int
        """
        return self.peekval

    def next(self):
        """
        :rtype: int
        """
        val = self.peekval
        self.hasnext = self.it.hasNext()
        self.peekval = self.it.next() if self.hasnext else None
        return val

    def hasNext(self):
        """
        :rtype: bool
        """
        return self.hasnext
