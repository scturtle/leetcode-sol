class Solution(object):
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        v1 = map(int, version1.split('.'))
        while v1 and v1[-1] == 0:
            v1.pop()
        v2 = map(int, version2.split('.'))
        while v2 and v2[-1] == 0:
            v2.pop()
        if v1 < v2:
            return -1
        elif v1 > v2:
            return 1
        else:
            return 0
