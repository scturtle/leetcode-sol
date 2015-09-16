from __future__ import print_function
xrange = range


class Solution(object):
    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
        stack = []
        ans, op = 0, '+'
        i = 0
        while i < len(s):
            if s[i].isdigit():
                val = 0
                while i < len(s) and s[i].isdigit():
                    val = val * 10 + ord(s[i]) - ord('0')
                    i += 1
                ans = ans + val if op == '+' else ans - val
            elif s[i] in '+-':
                op = s[i]
                i += 1
            elif s[i] == '(':
                stack.append((ans, op))
                ans, op = 0, '+'
                i += 1
            elif s[i] == ')':
                pre, op = stack.pop()
                ans = pre + ans if op == '+' else pre - ans
                i += 1
            else:
                i += 1
        return ans

print(Solution().calculate("(1+(4+5+2)-3)+(6+8)"))
