1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode() : val(0), next(nullptr) {}
7 *     ListNode(int x) : val(x), next(nullptr) {}
8 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
9 * };
10 */
11class Solution {
12public:
13    void reorderList(ListNode* head) {
14        vector<ListNode*> ptrs;
15        ListNode* start = head;
16        while(start){
17            ptrs.push_back(start);
18            start = start->next;
19        }
20
21        int left = 0, right = ptrs.size() - 1;
22        while(left < right){
23            ptrs[left]->next = ptrs[right];
24            ptrs[right]->next = ptrs[left+1];
25            left++;
26            right--;
27        }
28
29        ptrs[left]->next = NULL;
30    }
31};
32
33// L1 -> L2 -> L3 -> L4 -> L5 -> L6
34// L1 -> L6 -> L2 -> L5 -> L3 -> L4
35
36
37// L1 -> L2 -> L3 -> L4 -> L5
38// L1 -> L5 -> L2 -> L4 -> L3
39