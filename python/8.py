class Solution(object):
    def myAtoi(self, s):
        """
        :type str: str
        :rtype: int
        """
        i = 0
        n = len(s)
        while i < n and s[i] == ' ':
            i += 1
        if i == n:
            return 0
        if s[i] in '+-':
            sign = -1 if s[i] == '-' else 1
            i += 1
        else:
            sign = 1
        if i == n:
            return 0
        v = 0
        while i < n and '0' <= s[i] <= '9':
            v = 10 * v + ord(s[i]) - ord('0')
            i += 1
        n = sign * v
        return max(-2147483648, min(2147483647, n))
