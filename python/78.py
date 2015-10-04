class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        n = len(nums)
        ans = []
        for k in range(n+1):
            for l in itertools.combinations(nums, k):
                ans.append(l)
        return ans
