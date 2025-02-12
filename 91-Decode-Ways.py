class Solution(object):
    def numDecodings(self, s):
        if(s.startswith(\0\) or s.find(\00\) != -1):
            return 0
        
        if(s.endswith(\0\) and int(s[-2]) > 2):
            return 0

        l = len(s)
        dp = []
        dp.append(1)
        for i in range(1, l):
            if s[i] == '0':
                if(int(s[i-1]) > 2):
                    return 0
                dp.append(dp[i-2]) if i >= 2 else dp.append(1)
            
            else:
                x = int(s[i-1])*10 + int(s[i])
                dp.append(dp[i-1] + dp[i-2]) if x > 10 and x <= 26 else dp.append(dp[i-1])
        return dp[l-1]
        