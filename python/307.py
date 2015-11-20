class Node:
    __slot__ = "l r lt rt s"

    def __init__(self, l, r):
        self.l = l
        self.r = r


class NumArray(object):

    @staticmethod
    def _build(l, r, nums):
        root = Node(l, r)
        if l == r:
            root.s = nums[l]
        else:
            m = (l+r) // 2
            root.lt = NumArray._build(l, m, nums)
            root.rt = NumArray._build(m+1, r, nums)
            root.s = root.lt.s + root.rt.s
        return root

    def __init__(self, nums):
        """
        initialize your data structure here.
        :type nums: List[int]
        """
        if not nums:
            return
        self.root = NumArray._build(0, len(nums)-1, nums)

    def update(self, i, val, root=None):
        """
        :type i: int
        :type val: int
        :rtype: int
        """
        if root is None:
            root = self.root
        if root.l == root.r:
            root.s = val
            return
        m = (root.l + root.r) // 2
        if i <= m:
            self.update(i, val, root.lt)
        else:
            self.update(i, val, root.rt)
        root.s = root.lt.s + root.rt.s

    def sumRange(self, i, j, root=None):
        """
        sum of elements nums[i..j], inclusive.
        :type i: int
        :type j: int
        :rtype: int
        """
        if root is None:
            root = self.root
        if i == root.l and j == root.r:
            return root.s
        m = (root.l + root.r) // 2
        if j <= m:
            return self.sumRange(i, j, root.lt)
        elif i > m:
            return self.sumRange(i, j, root.rt)
        else:
            return self.sumRange(i, m, root.lt) +\
                   self.sumRange(m+1, j, root.rt)
