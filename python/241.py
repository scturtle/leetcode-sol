
class Solution(object):
    def diffWaysToCompute(self, input):
        """
        :type input: str
        :rtype: List[int]
        """
        if input.isdigit():
            return [int(input)]
        res = []
        op = {'+': lambda a, b: a+b,
              '-': lambda a, b: a-b,
              '*': lambda a, b: a*b}
        for i, c in enumerate(input):
            if c in '+-*':
                lefts = self.diffWaysToCompute(input[:i])
                rights = self.diffWaysToCompute(input[i+1:])
                res.extend([op[c](l, r) for l in lefts for r in rights])
        return res


sol = Solution()
print(sol.diffWaysToCompute("15-7*6+24"))
