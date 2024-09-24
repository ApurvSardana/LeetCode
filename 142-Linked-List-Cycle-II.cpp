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
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr || head -> next == nullptr) return nullptr;

        ListNode* sp = head;
        ListNode* fp = head;

        while(sp!=nullptr && fp!=nullptr && sp -> next != nullptr && fp -> next != nullptr && fp -> next -> next != nullptr)
        {
            sp = sp -> next;
            fp = fp -> next -> next;

            if(sp == fp)
            {
                fp = head;
                while(sp != nullptr && sp -> next != nullptr && sp != nullptr && sp -> next != nullptr)
                {
                    if(sp == fp)
                    return sp;

                    sp = sp -> next;
                    fp = fp -> next;
                }
            }
        }
        return nullptr;
        
    }
};