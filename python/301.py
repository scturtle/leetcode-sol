import collections


class Solution(object):
    @staticmethod
    def isValid(s):
        l = 0
        for c in s:
            if c == '(':
                l += 1
            elif c == ')':
                if not l:
                    return False
                l -= 1
        return l == 0

    def removeInvalidParentheses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        q = collections.deque()
        found = False
        saw = set()
        ans = []
        q.append(s)
        while(q):
            s = q.popleft()
            if self.isValid(s):
                ans.append(s)
                found = True
            if found:
                continue
            for i in range(len(s)):
                if s[i] not in '()':
                    continue
                ss = s[:i] + s[i+1:]
                if ss not in saw:
                    saw.add(ss)
                    q.append(ss)
        return ans
