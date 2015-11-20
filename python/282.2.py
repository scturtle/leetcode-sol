class Solution(object):
    @staticmethod
    def dfs(num, target, i, cur, sums, prods, ans):
        if i == len(num):
            if sums + prods == target:
                ans.append(''.join(cur))
            return
        for j in xrange(i+1, (i+1 if num[i] == '0' else len(num))+1):
            ds = num[i:j]
            if i == 0:
                cur.append(ds)
                Solution.dfs(num, target, j, cur, 0, int(ds), ans)
                cur.pop()
                continue
            for op in '+-*':
                cur.append(op)
                cur.append(ds)
                if op == '+':
                    newsums, newprods = sums + prods, int(ds)
                elif op == '-':
                    newsums, newprods = sums + prods, -int(ds)
                else:
                    newsums, newprods = sums, prods * int(ds)
                Solution.dfs(num, target, j, cur, newsums, newprods, ans)
                cur.pop()
                cur.pop()

    def addOperators(self, num, target):
        """
        :type num: str
        :type target: int
        :rtype: List[str]
        """
        ans = []
        self.dfs(num, target, 0, [], 0, 1, ans)
        return ans
