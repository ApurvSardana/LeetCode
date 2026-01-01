1class Solution:
2    def plusOne(self, digits: List[int]) -> List[int]:
3        ptr = len(digits)-1
4
5        while ptr >= 0:
6            if digits[ptr] < 9:
7                digits[ptr] += 1
8                break
9            else:
10                digits[ptr] = 0
11                ptr -= 1
12        
13        if ptr == -1:
14            digits.insert(0,1)
15        
16        return digits