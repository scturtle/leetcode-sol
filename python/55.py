class Solution(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        mx = 0
        for i, n in enumerate(nums):
            if mx < i:
                return False
            mx = max(mx, i+n)
        return True
