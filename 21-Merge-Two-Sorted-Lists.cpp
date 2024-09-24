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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* s1 = list1;
        ListNode* s2 = list2;
        ListNode* ans = new ListNode();
        ListNode* phead = ans;

        while(s1 != nullptr && s2 != nullptr)
        {
            ListNode* newNode = new ListNode();
            if(s1 -> val <= s2 -> val)
            {
                newNode -> val = s1 -> val;
                s1 = s1 -> next;
            }

            else
            {
                newNode -> val = s2 -> val;
                s2 = s2 -> next;
            }

            ans -> next = newNode;
            ans = ans -> next;
        }

        if(s1 == nullptr)
        {
            ans -> next = s2;
        }

        else
        ans -> next = s1;

        return phead -> next;
        
    }
};