/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* s = head;
        while(s != nullptr)
        {
            s = s -> next;
            len++;
        }

        if(len == n)
        {
            head = head -> next;
            return head;
        }

        int k = len - n - 1;

        s = head;
        while(k--)
        {
            s = s -> next;
        }
        
        s -> next = s -> next -> next;

        return head;
        
    }
};