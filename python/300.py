class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        if not n:
            return 0
        tail = [0] * n
        tail[0] = nums[0]
        mx = 1
        for num in nums:
            if num > tail[mx-1]:
                tail[mx] = num
                mx += 1
            else:
                l, r = -1, mx-1
                while l+1 != r:
                    m = (l + r) // 2
                    # tail[l] < num and num <= tail[r]
                    if tail[m] < num:
                        l = m
                    else:
                        r = m
                tail[r] = num
        return mx
