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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* s1 = l1;
        ListNode* s2 = l2;
        ListNode* ans = new ListNode();
        ListNode* phead = ans;
        
        int reserve = 0;

        while(s1 != nullptr && s2 != nullptr)
        {
            ListNode* newNode = new ListNode();
            if(s1 -> val + s2 -> val + reserve >= 10)
            {
                newNode -> val = (s1 -> val + s2 -> val + reserve) - 10;
                reserve = 1;
            }

            else
            {
            newNode -> val = s1 -> val + s2 -> val + reserve;
            reserve = 0;
            }

            ans -> next = newNode;
            ans = ans -> next;
            s1 = s1 -> next;
            s2 = s2 -> next;
        }

        if(s1 == nullptr && s2 == nullptr) 
        {   
            if(reserve != 0)
        {
            ListNode* newNode = new ListNode(1);
            ans -> next = newNode;
        }
            return phead -> next;
        }

        else if(s1 == nullptr)
        {
            while(s2 != nullptr)
            {
                ListNode* newNode = new ListNode();
                if(s2 -> val + reserve >= 10)
                {
                    newNode -> val = (s2 -> val + reserve) - 10;
                    reserve = 1;
                }

                else
                {
                    newNode -> val = s2 -> val + reserve;
                    reserve = 0;
                }

                ans -> next = newNode;
                ans = ans -> next;
                s2 = s2 -> next;
            }
        }

        else
        {
            while(s1 != nullptr)
            {
                ListNode* newNode = new ListNode();
                if(s1 -> val + reserve >= 10)
                {
                    newNode -> val = (s1 -> val + reserve) - 10;
                    reserve = 1;
                }

                else
                {
                    newNode -> val = s1 -> val + reserve;
                    reserve = 0;
                }
                ans -> next = newNode;
                ans = ans -> next;
                s1 = s1 -> next;
            }
        }


        if(reserve != 0)
        {
            ListNode* newNode = new ListNode(1);
            ans -> next = newNode;
        }

        return phead -> next;


        
    }
};