class Solution(object):
    def findkth(self, nums1, n1, nums2, n2, k):
        if n1 > n2:
            nums1, nums2 = nums2, nums1
            n1, n2 = n2, n1
        if n1 == 0:
            return nums2[k]
        if k == 0:
            return min(nums1[0], nums2[0])

        i1 = min((k+1)/2, n1)  # tricky
        i2 = k+1-i1
        if nums1[i1-1] < nums2[i2-1]:
            return self.findkth(nums1[i1:], n1-i1, nums2, n2, k-i1)
        elif nums1[i1-1] > nums2[i2-1]:
            return self.findkth(nums1, n1, nums2[i2:], n2-i2, k-i2)
        else:
            return nums1[i1-1]

    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        n1, n2 = len(nums1), len(nums2)
        n = n1 + n2
        if n == 0:
            return 0.0
        elif n & 1:
            return self.findkth(nums1, n1, nums2, n2, n / 2)
        else:  # tricky
            return (self.findkth(nums1, n1, nums2, n2, n / 2 - 1) +
                    self.findkth(nums1, n1, nums2, n2, n / 2)) / 2.0
