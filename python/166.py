class Solution(object):
    def fractionToDecimal(self, nu, de):
        """
        :type numerator: int
        :type denominator: int
        :rtype: str
        """
        sign = '-' if nu * de < 0 else ''
        nu, de = abs(nu), abs(de)
        ans = str(nu // de)
        nu %= de
        if nu == 0:
            return sign + ans
        else:
            ans += '.'
        d = {}
        i = 0
        while nu:
            if nu in d:
                ln = i-d[nu]
                return sign + ans[:-ln] + '(' + ans[-ln:] + ')'
            ans += str((nu * 10) // de)
            nxt_nu = (nu * 10) % de
            if nxt_nu == 0:
                return sign + ans
            d[nu] = i
            i += 1
            nu = nxt_nu
