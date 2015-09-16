xrange = range


class Solution(object):
    def containsNearbyAlmostDuplicate(self, nums, k, t):
        """
        :type nums: List[int]
        :type k: int
        :type t: int
        :rtype: bool
        """
        d = {}
        for i, n in enumerate(nums):
            kn = n // max(1, t)
            for km in (kn-1, kn, kn+1):
                # rm = []
                if km not in d:
                    d[km] = set()
                for (j, m) in d[km]:
                    if i-j <= k:
                        if abs(n-m) <= t:
                            return True
                #     else:
                #         rm.append((j, m))
                # for tupl in rm:
                #     d[km].remove(tupl)
            d[kn].add((i, n))
        return False

sol = Solution()
f = sol.containsNearbyAlmostDuplicate
assert f([], 0, 0) == False
assert f([0], 0, 0) == False
assert f([1, 1], 1, 0) == True
assert f([1, 3, 1], 2, 0) == True
assert f([2, 1], 1, 1) == True
