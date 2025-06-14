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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        ListNode* start = head;
        int length = 0;
        while(start){
            length++;
            start = start->next;
        }

        int rotations = k%length;
        if(rotations == 0 || length < 2) return head;

        ListNode* new_last = head, *new_head = head;
        int times = length-rotations;
        while(times--){
            new_last = new_head;
            new_head = new_head->next;
        }

        ListNode* old_last = new_head;
        while(old_last->next) old_last = old_last->next;

        old_last->next = head;
        new_last->next = nullptr;
        
        return new_head;
    }
};