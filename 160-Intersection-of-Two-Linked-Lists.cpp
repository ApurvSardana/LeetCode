/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        if(headA == headB) return headA;
        int countA = 0, countB = 0;
        ListNode* tempA = headA;
        ListNode* tempB = headB;

        while(tempA != nullptr)
        {
            tempA = tempA -> next;
            countA++;
        }

        while(tempB != nullptr)
        {
            tempB = tempB -> next;
            countB++;
        }

        tempA = headA;
        tempB = headB;

        if(countA >= countB)
        {
            int i = countA - countB;
            while(i--)
            {
                tempA = tempA -> next;
            }
        }

        else
        {
            int i = countB - countA;
            while(i--)
            {
                tempB = tempB -> next;
            }
        }

        if(tempA == tempB) return tempA;

        while(tempA -> next != nullptr && tempB -> next != nullptr)
        {
            if(tempA -> next == tempB -> next)
            return tempA -> next;

            else
            {
                tempA = tempA -> next;
                tempB = tempB -> next;
            }
        }

        return nullptr;

        
    }
};