class Solution(object):
    def getHint(self, secret, guess):
        """
        :type secret: str
        :type guess: str
        :rtype: str
        """
        a = [0] * 10
        b = [0] * 10
        A = 0
        for i in range(len(guess)):
            if secret[i] == guess[i]:
                A += 1
            else:
                a[int(secret[i])] += 1
                b[int(guess[i])] += 1
        B = sum(min(a[i], b[i]) for i in range(10))
        return '{}A{}B'.format(A, B)
