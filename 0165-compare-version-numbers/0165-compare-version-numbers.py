class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        v1 = version1.split('.')
        v2 = version2.split('.')

        l = max(len(v1), len(v2))

        if(len(v1) < l):
            while(len(v1) < l):
                v1.append(0)
        
        if(len(v2) < l):
            while(len(v2) < l):
                v2.append(0)

        for i in range(l):
            if(int(v1[i]) < int(v2[i])):
                return -1
            elif(int(v1[i]) > int(v2[i])):
                return 1

        return 0