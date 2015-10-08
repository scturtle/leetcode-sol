from operator import add, sub, mul, truediv

class Solution(object):
    def evalRPN(self, tokens):
        """
        :type tokens: List[str]
        :rtype: int
        """
        ops = {'+':add, '-':sub, '*':mul,
               '/':lambda a, b: int(truediv(a, b))}
        stack = []
        for t in tokens:
            if t in ops:
                b, a = stack.pop(), stack.pop()
                stack.append(ops[t](a, b))
            else:
                stack.append(int(t))
        return stack.pop()
