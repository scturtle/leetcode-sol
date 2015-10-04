class Solution(object):
    # from 84
    def largestRectangleArea(self, height):
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

    def maximalRectangle(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        n = len(matrix)
        if not n:
            return 0
        m = len(matrix[0])
        if not m:
            return 0
        height = [0] * m
        ans = 0
        for i in xrange(n):
            for j in xrange(m):
                height[j] = 0 if matrix[i][j] == '0' else 1 + height[j]
            ans = max(ans, self.largestRectangleArea(height))
        return ans
