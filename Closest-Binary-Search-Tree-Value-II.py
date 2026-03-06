1# Definition for a binary tree node.
2# class TreeNode:
3#     def __init__(self, val=0, left=None, right=None):
4#         self.val = val
5#         self.left = left
6#         self.right = right
7class Solution:
8    def dfs(self, node: TreeNode, target: float, k: int) -> None:
9        if not node: return
10
11        if len(self.pq) < k: heapq.heappush(self.pq,[-abs(target-node.val),node.val])
12        elif -self.pq[0][0] > abs(target-node.val):
13            heapq.heappop(self.pq)
14            heapq.heappush(self.pq, [-abs(target-node.val),node.val])
15
16        self.dfs(node.left, target, k)
17        self.dfs(node.right, target, k)
18
19    def closestKValues(self, root: Optional[TreeNode], target: float, k: int) -> List[int]:
20        self.pq = []
21
22        self.dfs(root,target,k)
23
24        ans = []
25        while self.pq:
26            ans.append(heapq.heappop(self.pq)[1])
27        
28        return ans