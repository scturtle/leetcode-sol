class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        add = 1
        for i in xrange(len(digits)-1, -1, -1):
            d = digits[i]
            digits[i] = (d + add) % 10
            add = (d + add) / 10
        return [1] + digits if add else digits
