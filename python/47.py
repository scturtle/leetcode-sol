class Solution(object):
    def permuteUnique(self, nums, idx=None):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        idx = 0 if idx is None else idx
        if idx == len(nums):
            return [[]]

        ans = []
        used = set()
        for j in range(idx, len(nums)):
            if nums[j] in used:
                continue
            used.add(nums[j])
            nums[idx], nums[j] = nums[j], nums[idx]
            for l in self.permuteUnique(nums, idx+1):
                ans.append([nums[idx]] + l)
            nums[idx], nums[j] = nums[j], nums[idx]
        return ans

s = Solution()
for l in s.permuteUnique(sorted([1, 1, 2])):
    print(l)
