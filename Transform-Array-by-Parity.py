class Solution(object):
    def transformArray(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        n = len(nums)
        for i in range(n):
            if(nums[i]%2 == 0):
                nums[i] = 0
            else:
                nums[i] = 1
        
        return sorted(nums)
            