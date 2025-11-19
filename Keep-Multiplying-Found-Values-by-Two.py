class Solution:
    def findFinalValue(self, nums: List[int], original: int) -> int:
        flag = True
        while flag:
            if original in nums:
                original *= 2
            else:
                flag = False
        return original