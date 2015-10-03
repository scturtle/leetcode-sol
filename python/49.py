class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        d = collections.defaultdict(list)
        for s in strs:
            d[''.join(sorted(s))].append(s)
        return [sorted(v) for v in d.itervalues()]
