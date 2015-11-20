class NumArray(object):
    def __init__(self, nums):
        """
        initialize your data structure here.
        :type nums: List[int]
        """
        n = len(nums)
        if not n:
            return
        self.s = [0] * (n + 1)
        for i in range(1, n+1):
            self.s[i] = self.s[i-1] + nums[i-1]

    def sumRange(self, i, j):
        """
        sum of elements nums[i..j], inclusive.
        :type i: int
        :type j: int
        :rtype: int
        """
        return self.s[j+1] - self.s[i]


# Your NumArray object will be instantiated and called as such:
numArray = NumArray([-4, -5])
print(numArray.sumRange(0, 0))
print(numArray.sumRange(1, 1))
