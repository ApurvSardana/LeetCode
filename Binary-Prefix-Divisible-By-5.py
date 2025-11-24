class Solution:
    def prefixesDivBy5(self, nums: List[int]) -> List[bool]:
        number = 0
        ans = []

        for bit in nums:
            number <<= 1
            number ^= bit
            if(number%5 == 0):
                ans.append(True)
            else:
                ans.append(False)
        
        return ans