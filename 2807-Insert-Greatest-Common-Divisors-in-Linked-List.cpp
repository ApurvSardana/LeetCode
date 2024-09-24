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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head -> next == nullptr) return head;

        ListNode* start = head;
        ListNode* s = start;
        ListNode* t = start -> next;
        int g = 0;

        while(t != nullptr)
        {
            g = gcd(s -> val, t -> val);
            ListNode* newNode = new ListNode();
            newNode -> val = g;
            newNode -> next = s -> next;
            s -> next = newNode;
            s = t;
            t = t -> next;
        }

        return start;
    }
};