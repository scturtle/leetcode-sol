class Solution(object):
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        nums.sort()
        n = len(nums)
        ans = set()
        for i in xrange(n - 3):
            if nums[i] > target and nums[i + 1] >= 0:
                break
            for j in xrange(i + 1, n - 2):
                s = nums[i] + nums[j]
                if s > target and nums[j + 1] >= 0:
                    break
                k, l = j + 1, n - 1
                while k < l:
                    t = s + nums[k] + nums[l]
                    if t == target:
                        ans.add((nums[i], nums[j], nums[k], nums[l]))
                        k += 1
                        l -= 1
                    elif t < target:
                        k += 1
                    else:
                        l -= 1
        return sorted(ans)
