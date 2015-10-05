import string
import collections


class Solution(object):
    def findLadders(self, beginWord, endWord, wordlist):
        """
        :type beginWord: str
        :type endWord: str
        :type wordlist: Set[str]
        :rtype: List[List[int]]
        """
        wordlist.add(endWord)
        cur = [beginWord]
        saw = {beginWord, }
        pre = collections.defaultdict(set)
        while cur:
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
                        pre[nw].add(w)
            if endWord in nxt:
                break
            for nw in nxt:
                saw.add(nw)
            cur = nxt

        ans = []
        def dfs(l):
            if l[-1] == beginWord:
                ans.append(l[::-1])
                return
            for pw in pre[l[-1]]:
                l.append(pw)
                dfs(l)
                l.pop()
        dfs([endWord])
        return ans


s = Solution()
print(s.findLadders("hit", "cog", {"hot","dot","dog","lot","log"}))
