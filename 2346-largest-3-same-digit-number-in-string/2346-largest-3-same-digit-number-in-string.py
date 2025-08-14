class Solution:
    def largestGoodInteger(self, num: str) -> str:
        n = len(num)
        mx_num = -1
        ans = ""
        for i in range(1, n-1):
            if(num[i-1] == num[i] and num[i] == num[i+1] and int(num[i-1:i+2]) > mx_num):
                ans = num[i-1:i+2]
                mx_num = int(num[i-1:i+2])
        return ans
