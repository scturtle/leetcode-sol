class Solution(object):
    def sortedArrayToBST(self, nums, l=None, r=None):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        if l is None:
            l, r = 0, len(nums)
        if l == r:
            return None
        m = (l + r) / 2
        root = TreeNode(nums[m])
        root.left = self.sortedArrayToBST(nums, l, m)
        root.right = self.sortedArrayToBST(nums, m+1, r)
        return root
