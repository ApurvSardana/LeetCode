1class Solution:
2    def isValid(self, code, businessLine, isActive):
3        a,z,A,Z,zero,nine,_ = ord('a'),ord('z'),ord('A'),ord('Z'),ord('0'),ord('9'),ord('_')
4        lines = ["electronics", "grocery", "pharmacy", "restaurant"]
5
6        for letter in code:
7            l = ord(letter)
8            if (l >= a and l <= z) or (l >= A and l <= Z) or (l >= zero and l <= nine) or (l == _):
9                continue
10            else:
11                return False
12
13        return code != '' and businessLine in lines and isActive
14
15    def validateCoupons(self, code: List[str], businessLine: List[str], isActive: List[bool]) -> List[str]:
16        n = len(code)
17        validCoupons = []
18        for i in range(n):
19            if self.isValid(code[i],businessLine[i],isActive[i]):
20                validCoupons.append([businessLine[i], code[i]])
21        
22        validCoupons.sort()
23        ans = []
24        for coupon in validCoupons:
25            ans.append(coupon[1])
26
27        return ans