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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head -> next == nullptr)
        return head;

        ListNode* s = head;
        ListNode* t = head -> next;
        ListNode* r = nullptr;

        if(head -> next -> next)
        r = head -> next -> next;

        while(r != nullptr && r -> next != nullptr)
        {
            swap(s -> val, t -> val);
            s = s -> next -> next;
            t = t -> next -> next;
            r = r -> next -> next;
        }

        swap(s -> val, t -> val);

        return head;
        
    }
};