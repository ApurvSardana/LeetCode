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
    void deleteNode(ListNode* node) {
        ListNode* nextNode = node->next;
        ListNode* prev = node;
        while(node && nextNode){
            swap(node->val, nextNode->val);
            prev = node;
            node = node->next;
            nextNode = nextNode->next;
        }

        prev->next = nullptr;
    }
};