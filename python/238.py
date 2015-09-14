class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        left = [1]
        n = len(nums)
        for i in range(n):
            left.append(nums[i]*left[-1])
        right = [1]
        for i in range(n-1, -1, -1):
            right.append(nums[i]*right[-1])
        res = []
        for i in range(n):
            res.append(left[i] * right[n-i-1])
        return res

print(Solution().productExceptSelf([1,2,3,4]))
