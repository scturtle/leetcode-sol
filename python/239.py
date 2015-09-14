import collections


class Solution(object):
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        # maintain index of decreasing  possiable maximium values
        q = collections.deque()
        res = []
        for i, n in enumerate(nums):
            if q and q[0] <= i-k:
                q.popleft()
            while q and nums[q[-1]] < n:
                q.pop()
            q.append(i)
            res.append(nums[q[0]])
        return res[k-1:]

sol = Solution()
print(sol.maxSlidingWindow([1,3,-1,-3,5,3,6,7], 3))
