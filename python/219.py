import collections


class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        c = collections.Counter()
        for i, n in enumerate(nums):
            if i-k-1 >= 0:
                c[nums[i-k-1]] -= 1
            if c[n]:
                return True
            c[n] += 1
        return False
