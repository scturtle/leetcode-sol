import string
import collections


class Solution(object):
    def ladderLength(self, beginWord, endWord, wordlist):
        """
        :type beginWord: str
        :type endWord: str
        :type wordlist: Set[str]
        :rtype: int
        """
        wordlist.add(endWord)
        cur = [beginWord]
        saw = {beginWord, }
        ln = 1
        while cur:
            if endWord in cur:
                return ln
            ln += 1
            nxt = set()
            for w in cur:
                for i, c in enumerate(w):
                    st, ed = w[:i], w[i+1:]
                    for nc in string.ascii_lowercase:
                        if nc == c:
                            continue
                        nw = st + nc + ed
                        if nw not in wordlist or nw in saw:
                            continue
                        nxt.add(nw)
            for nw in nxt:
                saw.add(nw)
            cur = nxt

        return 0


s = Solution()
print(s.ladderLength("hit", "cog", {"hot","dot","dog","lot","log"}))
