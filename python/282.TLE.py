import itertools


class Solution(object):
    def addOperators(self, num, target):
        """
        :type num: str
        :type target: int
        :rtype: List[str]
        """
        n = len(num)
        ans = []
        for c in range(n):
            for poses in itertools.combinations(range(1, n), c):
                bad = False
                np = len(poses)
                for i in range(np):
                    pj = poses[i+1] if i+1 < np else n
                    if num[poses[i]] == '0' and pj-i > 1:
                        bad = True
                        break
                if bad:
                    continue
                for ops in itertools.product('+-*', repeat=c):
                    s = ''
                    i = 0
                    for pos, op in zip(poses, ops):
                        s += num[i:pos] + op
                        i = pos
                    s += num[i:]
                    if eval(s) == target:
                        ans.append(s)
        return ans
