class Solution(object):

    @staticmethod
    def get_lefts(height):
        maxh = 0
        ans = []
        for h in height:
            maxh = max(maxh, h)
            ans.append(maxh)
        return ans

    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        lefts = Solution.get_lefts(height)
        rights = Solution.get_lefts(height[::-1])[::-1]
        volume = 0
        for i in xrange(len(height)):
            volume += min(lefts[i], rights[i]) - height[i]
        return volume
