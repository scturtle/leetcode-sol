class Solution(object):
    def largestRectangleArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        n = len(height)
        stack = []
        lefts = []
        rights = [n] * n
        for i, h in enumerate(height):
            while stack and height[stack[-1]] > h:  # >=
                rights[stack.pop()] = i             # tricky!
            lefts.append(-1 if not stack else stack[-1])
            stack.append(i)
        ans = 0
        for h, l, r in zip(height, lefts, rights):
            ans = max(ans, (r-l-1) * h)
        return ans
