class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums.sort()
        best = sum(nums[:3])
        n = len(nums)
        for i in xrange(n-2):
            j, k = i+1, n-1
            while j < k:
                # print (nums[i], nums[j], nums[k]), best
                s = nums[i] + nums[j] + nums[k]
                if abs(s-target) < abs(best-target):
                    best = s
                if s == target:
                    return target
                elif s < target:
                    j += 1
                else:
                    k -= 1
        return best
