class LRUCache(object):

    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.cap = capacity
        self.cache = collections.OrderedDict()

    def get(self, key):
        """
        :rtype: int
        """
        if key not in self.cache:
            return -1
        else:
            val = self.cache.pop(key)
            self.cache[key] = val
            return val

    def set(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: nothing
        """
        if key in self.cache:
            self.cache.pop(key)
        if len(self.cache) == self.cap:
            self.cache.popitem(last=False)
        self.cache[key] = value
