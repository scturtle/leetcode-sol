class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        item1 = item2 = None
        cnt1 = cnt2 = 0
        for n in nums:
            if n == item1:
                cnt1 += 1
            elif n == item2:
                cnt2 += 1
            elif cnt1 == 0:
                item1 = n
                cnt1 = 1
            elif cnt2 == 0:
                item2 = n
                cnt2 = 1
            else:
                cnt1 -= 1
                cnt2 -= 1
        print(item1, cnt1, item2, cnt2)
        return [n for n in (item1, item2)
                if n is not None and nums.count(n) > len(nums)//3]

print(Solution().majorityElement([1,2,2]))
