class Solution(object):
    @staticmethod
    def len(n):
        l = 1
        t = 10
        while True:
            if n < t:
                return l
            t *= 10
            l += 1

    def isAdditiveNumber(self, num):
        """
        :type num: str
        :rtype: bool
        """
        n = len(num)
        if n < 3:
            return False
        n1 = 0
        for i1 in range(n-2):
            n1 = 10 * n1 + int(num[i1])
            if i1 > 0 and num[0] == '0':
                return False
            n2 = 0
            for i2 in range(i1+1, n-1):
                n2 = 10 * n2 + int(num[i2])
                if i2 - i1 > 1 and num[i1+1] == '0':
                    continue
                i3 = i2 + 1
                pre = n2
                n3 = n1 + n2
                l = self.len(n3)
                while i3 + l <= n:
                    if num[i3:i3+l] != str(n3):
                        break
                    pre, n3 = n3, pre + n3
                    i3 += l
                    l = self.len(n3)
                if i3 == n:
                    print(n1, n2)
                    return True
        return False

s = Solution()
print(s.isAdditiveNumber("121474836472147483648"))
