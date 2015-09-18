def cnt(n, i):
    itv = pow(2, i)
    ans = (n + 1) // (2 * itv) * itv
    if (n + 1) % (2 * itv) > itv:
        ans += (n + 1) % (2 * itv) - itv
    return ans


class Solution(object):
    def rangeBitwiseAnd(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        k = len(bin(n)) - 2
        ans = 0
        for i in range(k):
            if cnt(n, i) - cnt(m-1, i) == n-m+1:
                ans += 1 << i
        return ans

print(Solution().rangeBitwiseAnd(5, 7))
