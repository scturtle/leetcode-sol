class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        l, r = 0, len(height)-1
        ans = 0
        while l < r:
            ans = max(ans, min(height[l], height[r]) * (r-l))
            if height[l] <= height[r]:
                h = height[l]
                while l < r and height[l] <= h:
                    l += 1
            else:
                h = height[r]
                while l < r and height[r] <= h:
                    r -= 1
        return ans
