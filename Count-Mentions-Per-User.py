1class Solution:
2    def countMentions(self, n: int, events: List[List[str]]) -> List[int]:
3        ans = [0]*n
4        offlineTill= [0]*n
5
6        events.sort(key = lambda x : (int(x[1]), -ord(x[0][0])))
7        
8        for Type,time,Ids  in events:
9            if Type == 'MESSAGE':
10                if Ids == 'ALL':
11                    for i in range(n):
12                        ans[i] += 1
13                
14                elif Ids == 'HERE':
15                    for i in range(n):
16                        if offlineTill[i] <= int(time):
17                            ans[i] += 1
18                
19                else:
20                    mentioned = map(lambda s : int(s[2:]), Ids.split(' '))
21                    for user in mentioned:
22                        ans[user] += 1
23
24            else:
25                offlineTill[int(Ids)] = int(time)+60
26            
27        return ans