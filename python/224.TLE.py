from __future__ import print_function


class Solution(object):
    # @profile
    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
        s = s.replace(' ', '')
        n = len(s)
        i = 0
        ans = 0
        op = '+'
        while i < len(s):
            if s[i] == '(':
                cnt = 1
                j = i+1
                while cnt:
                    if s[j] == '(':
                        cnt += 1
                    elif s[j] == ')':
                        cnt -= 1
                    j += 1
                val = self.calculate(s[i+1:j-1])
                ans = ans+val if op == '+' else ans-val
                i = j
            elif '0' <= s[i] <= '9':
                val = ''
                while i < n and '0' <= s[i] <= '9':
                    val += s[i]
                    i += 1
                val = int(val)
                ans = ans+val if op == '+' else ans-val
            elif s[i] in '+-':
                op = s[i]
                i += 1
        return ans

print(Solution().calculate("(1+(4+5+2)-3)+(6+8)"))
