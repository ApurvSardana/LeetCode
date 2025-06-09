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
    ListNode* reverse(ListNode* head2){
        ListNode* p = nullptr;
        ListNode* q = nullptr;
        ListNode* r = head2;

        while(r){
            p = q;
            q = r;

            r = r->next;
            q->next = p;
        }

        return q;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* middle = slow;
        ListNode* head2 = middle->next;
        middle->next = nullptr;
        head2 = reverse(head2);

        while(head && head2){
            if(head->val != head2->val) return false;
            head = head->next;
            head2 = head2->next;
        }

        return true;
    }
};