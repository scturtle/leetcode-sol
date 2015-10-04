class Solution(object):
    @staticmethod
    def dfs(kvs, idx, cur, ans):
        if idx == len(kvs):
            ans.append(cur[:])
            return
        k, v = kvs[idx]
        for i in xrange(v+1):
            Solution.dfs(kvs, idx+1, cur, ans)
            cur.append(k)
        for i in xrange(v+1):
            cur.pop()

    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        kvs = [(k, len(list(v))) for k, v in itertools.groupby(nums)]
        ans = []
        Solution.dfs(kvs, 0, [], ans)
        return ans
