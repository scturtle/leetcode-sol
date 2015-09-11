class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        for i in range(n):
            while nums[i] != i:
                j = nums[i]
                if j == n:
                    break
                nums[i], nums[j] = nums[j], nums[i]
        print(nums)
        for i in range(n):
            if i != nums[i]:
                return i
        return n

sol = Solution()
print(sol.missingNumber([3, 2, 0]))
