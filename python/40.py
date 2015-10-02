class Solution(object):

    @staticmethod
    def dfs(nums, i, cur, remain, ans):
        if remain == 0:
            ans.append(cur[:])
            return
        if i == len(nums):
            return

        Solution.dfs(nums, i+1, cur, remain, ans)
        if remain >= nums[i]:
            cur.append(nums[i])
            Solution.dfs(nums, i+1, cur, remain - nums[i], ans)
            cur.pop()

    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        ans = []
        cur = []
        candidates.sort()
        Solution.dfs(candidates, 0, cur, target, ans)
        return [list(l) for l in set(tuple(t) for t in ans)]
