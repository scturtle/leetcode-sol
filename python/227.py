import re


class Solution(object):
    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
        op = {"+": lambda a, b: a+b, "-": lambda a, b: a-b,
              "*": lambda a, b: a*b, "/": lambda a, b: a//b}
        l = re.split("(:?[\+\-\*\/])", s.replace(" ", ""))
        l2 = []
        # print(l)
        for t in l:
            if t.isdigit():
                # print(t, l2)
                if len(l2) >= 2 and l2[-1] in '*/':
                    o = l2.pop()
                    a = l2.pop()
                    l2.append(op[o](int(a), int(t)))
                else:
                    l2.append(int(t))
            else:
                l2.append(t)
        # print(l2)
        ans = l2[0]
        for i in range(1, len(l2)-1, 2):
            ans = op[l2[i]](ans, l2[i+1])
        return ans

print(Solution().calculate("0*1"))
