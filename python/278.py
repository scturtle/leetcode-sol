# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
def isBadVersion(version):
    return version >= 10

class Solution(object):
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        if isBadVersion(1):
            return 1
        l, r = 1, n
        while l+1 != r:
            m = (l+r) / 2
            badm = isBadVersion(m)
            if badm:
                r = m
            else:
                l = m
        return r

print Solution().firstBadVersion(100)
