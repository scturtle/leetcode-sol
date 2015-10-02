class Solution(object):
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        sign = -1 if (dividend < 0 and divisor > 0) or\
                     (dividend > 0 and divisor < 0) else 1
        dividend, divisor = abs(dividend), abs(divisor)
        ans = 0
        i = 0
        while divisor << (i + 1) <= dividend:
            i += 1
        while dividend and i != -1:
            cur = divisor << i
            while dividend >= cur:
                dividend -= cur
                ans += 1 << i
            i -= 1
        return max(-1 << 31, min(sign * ans, (1 << 31) - 1))
