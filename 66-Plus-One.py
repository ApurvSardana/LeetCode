class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        def f(d, n):
            if d[n] != 9:
                d[n] += 1
                return digits
            
            elif n != 0:
                d[n] = 0
                return f(d, n-1)

            else:
                d[n] = 0
                d.insert(0, 1)
                return d

        digits = f(digits, len(digits)-1)
        return digits