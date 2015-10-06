class Solution(object):
    def candy(self, rts):
        """
        :type rts: List[int]
        :rtype: int
        """
        n = len(rts)
        c = [1] * n
        l = list(enumerate(rts))
        l.sort(key=lambda t: t[1])
        for i, r in l:
            c[i] = max(c[i], c[i-1]+1 if i and rts[i-1]<r else 0)
            c[i] = max(c[i], c[i+1]+1 if i+1<n and rts[i+1]<r else 0)
        return sum(c)
