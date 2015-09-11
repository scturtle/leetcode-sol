import heapq

class Solution(object):
    def nthUglyNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        q = [1]
        i2 = i3 = i5 = 0
        for i in range(n-1):
            m2, m3, m5 = q[i2]*2, q[i3]*3, q[i5]*5
            mi = min(m2, m3, m5)
            q.append(mi)
            if mi == m2:
                i2 += 1
            if mi == m3:
                i3 += 1
            if mi == m5:
                i5 += 1
        return q[-1]

print(Solution().nthUglyNumber(10))
