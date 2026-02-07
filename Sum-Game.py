1class Solution:
2    def sumGame(self, num: str) -> bool:
3        n = len(num)
4        sum1,sum2 = sum([ord(ch)-ord('0') if ch != '?' else 0 for ch in num[:n//2]]),sum([ord(ch)-ord('0') if ch != '?' else 0 for ch in num[n//2:]])
5        q1,q2 = num[:n//2].count('?'),num[n//2:].count('?')
6        if sum1 == sum2:
7            return q1 != q2
8        
9        elif sum1 < sum2:
10            return q1 <= q2 or sum1 + ((q1-q2)//2)*9 < sum2 or sum1 + ((q1-q2+1)//2)*9 > sum2
11
12        else:
13            return q1 >= q2 or sum2 + ((q2-q1)//2)*9 < sum1 or sum2 + ((q2-q1+1)//2)*9 > sum1