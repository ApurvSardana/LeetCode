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
    ListNode* newHead;

    vector<ListNode*> reverseGroup(ListNode* prev_follow, ListNode* follow, ListNode* lead, ListNode* next_lead){
        if(!lead || !follow) return {prev_follow, follow, lead, next_lead};

        ListNode* r = follow -> next;
        ListNode* q = follow;
        ListNode* p = follow;

        while(q != lead){
            p = q;
            q = r;
            r = r-> next;

            q -> next = p;
        }

        if(!prev_follow) newHead = q;
        else prev_follow -> next = q;

        follow -> next = next_lead;
        prev_follow = follow;
        follow = lead = next_lead;

        return {prev_follow, follow, lead, next_lead};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* lead = head;
        ListNode* follow = lead;

        ListNode* prev_follow = nullptr;
        ListNode* next_lead = nullptr;
        while(lead){
            for(int i = 0; i < k-1 && lead; i++)
                lead = lead -> next;
            
            if(!lead) break;
            next_lead = lead -> next;

            vector<ListNode*> newState = reverseGroup(prev_follow, follow, lead, next_lead);

            prev_follow = newState[0];
            follow = newState[1];
            lead = newState[2];
            next_lead = newState[3];
        }

        return newHead;
    }
};