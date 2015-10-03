class Solution(object):
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) <= 1:
            return 0
        cnt, best, last = 0, 0, -1
        for i, n in enumerate(nums):
            cur = i + nums[i]
            if i <= last:
                # print(cnt-1, best)
                # in the shadow of last jump
                if cur > best:
                    best = cur
            else:
                # print(cnt, best)
                # in the shadow best jump
                if i + nums[i] > best:
                    last = best
                    best = i + nums[i]
                    cnt += 1
            if best >= len(nums)-1:
                return cnt
        return -1

s = Solution()
print(s.jump([1]))
print(s.jump([1, 2]))
