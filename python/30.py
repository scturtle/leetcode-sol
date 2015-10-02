import collections
xrange = range


class Solution(object):
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        n = len(s)
        m = len(words[0])
        words_dict = {w: i for i, w in enumerate(words)}
        words_cnt = collections.Counter(words_dict[w] for w in words)
        ans = []
        for i in xrange(m):  # offset of s
            # word to number
            idxs = [words_dict.get(s[j:j + m], -1) for j in xrange(i, n, m)]
            # running window
            ln = len(idxs)
            l = r = 0
            saw = collections.Counter()
            cnt = 0
            while r < ln:
                while saw[idxs[r]] == words_cnt[idxs[r]] > 0:
                    # if cannot add, pop left
                    saw[idxs[l]] -= 1
                    cnt -= 1
                    l += 1
                if idxs[r] != -1:  # clear
                    saw[idxs[r]] += 1
                    cnt += 1
                else:  # add
                    saw.clear()
                    cnt = 0
                    l = r + 1
                r += 1
                if cnt == len(words) and saw == words_cnt:
                    # found
                    ans.append(i + l * m)
        return ans


print(Solution().findSubstring("barfoothefoobarman", ["foo", "bar"]))
print(Solution().findSubstring("wordgoodgoodgoodbestword", ["word", "good",
                                                            "best", "good"]))
