import itertools
from functools import reduce


class Solution(object):
    def addOperators(self, num, target):
        """
        :type num: str
        :type target: int
        :rtype: List[str]
        """
        self.num = num
        self.n = len(num)
        return [s for s, v in self.add_sub(num, init=True)
                if v == target]

    def add_sub(self, num, *, init=False):
        if not num:
            yield '', 0
        for j in range(1, len(num)+1):
            for s1, v1 in self.mul(num[:j]):
                for s2, v2 in self.add_sub(num[j:]):
                    if init:
                        yield s1+s2, v1+v2
                    else:
                        yield '+'+s1+s2, v1+v2
                        yield '-'+s1+s2, -v1+v2

    def mul(self, num):
        for c in range(len(num)):
            for poses in itertools.combinations(range(1, len(num)), c):
                ns = []
                i = 0
                for p in poses:
                    ns.append(num[i:p])
                    i = p
                ns.append(num[i:])
                for n in ns:
                    if n[0] == '0' and len(n) > 1:
                        break
                else:
                    yield '*'.join(ns), reduce(int.__mul__, map(int, ns), 1)

sol = Solution()
# print(list(sol.mul('123')))
print(list(sol.addOperators('123', 6)))
print(list(sol.addOperators('105', 5)))
