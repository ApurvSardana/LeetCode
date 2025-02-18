class Solution:
    def __init__(self):
        self.s = set()

    def isHappy(self, n: int) -> bool:
        if n == 1:
            return True
        
        elif n in self.s:
            return False
        
        else:
            num = n
            self.s.add(n)
            n = 0
            while num != 0:
                n += (num % 10)**2
                num //= 10
            return self.isHappy(n)

