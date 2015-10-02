class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        ans = 'M' * (num / 1000)
        num %= 1000
        if num >= 900:
            ans += 'CM'
            num -= 900

        ans += 'D' * (num / 500)
        num %= 500
        if num >= 400:
            ans += 'CD'
            num -= 400

        ans += 'C' * (num / 100)
        num %= 100
        if num >= 90:
            ans += 'XC'
            num -= 90

        ans += 'L' * (num / 50)
        num %= 50
        if num >= 40:
            ans += 'XL'
            num -= 40

        ans += 'X' * (num / 10)
        num %= 10
        if num >= 9:
            ans += 'IX'
            num -= 9

        ans += 'V' * (num / 5)
        num %= 5
        if num >= 4:
            ans += 'IV'
            num -= 4

        ans += 'I' * num
        return ans
