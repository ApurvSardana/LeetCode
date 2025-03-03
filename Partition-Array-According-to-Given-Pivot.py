class Solution:
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        ans1 = []
        ans2 = []
        ans3 = []

        for num in nums:
            if num < pivot:
                ans1.append(num)
            
            elif  num > pivot:
                ans3.append(num)

            else:
                ans2.append(num)

        return ans1 + ans2 + ans3