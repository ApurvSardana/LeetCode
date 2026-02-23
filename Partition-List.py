1# Definition for singly-linked list.
2# class ListNode:
3#     def __init__(self, val=0, next=None):
4#         self.val = val
5#         self.next = next
6class Solution:
7    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
8        prev_node,node,last_smaller = None,head, None
9        while node:
10            if node.val >= x:
11                prev_node = node
12                node = node.next
13            else:
14                if last_smaller:
15                    if last_smaller == prev_node:
16                        prev_node = node
17                        last_smaller = node
18                        node = node.next
19                        continue
20                    
21                    prev_node.next = node.next
22                    node.next = last_smaller.next
23                    last_smaller.next = node
24                    last_smaller = last_smaller.next
25                    node = prev_node.next
26                else:
27                    if prev_node:
28                        prev_node.next = node.next
29                        node.next = head
30                        head = node
31                        last_smaller = head
32                        node = prev_node.next
33                    else:
34                        last_smaller = node
35                        prev_node = node
36                        node = node.next
37        return head