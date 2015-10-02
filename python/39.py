class Solution(object):

    @staticmethod
    def dfs(nums, i, cur, remain, ans):
        if remain == 0:
            ans.append(cur[:])
            return
        if i == len(nums):
            return
        c = 0
        while remain >= 0:
            Solution.dfs(nums, i+1, cur, remain, ans)
            cur.append(nums[i])
            c += 1
            remain -= nums[i]
        while c:
            cur.pop()
            c -= 1

    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        ans = []
        cur = []
        candidates.sort()
        Solution.dfs(candidates, 0, cur, target, ans)
        return ans
