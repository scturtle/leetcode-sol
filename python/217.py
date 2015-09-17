class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        saw = set()
        for n in nums:
            if n in saw:
                return True
            saw.add(n)
        return False
