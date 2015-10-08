class Solution(object):
    def findRepeatedDnaSequences(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        n = len(s)
        if n < 10:
            return []
        a = [0] * 1050000
        ss = s
        s = [(0 if c == 'A' else 1 if c == 'C' else 2 if c == 'G' else 3) for c in s]
        h = 0
        for i in xrange(10):
            h += s[i] * (1<<2*i)
        a[h] = 1
        ans = []
        for i in xrange(1, n-10+1):
            h >>= 2
            h +=  s[i+9] * (1<<18)
            if a[h] == 1:
                ans.append(ss[i:i+10])
            a[h] += 1
        return ans
