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
    ListNode* head;
    Solution(ListNode* head) {
        this -> head = head;
    }
    
    int getRandom() {
        // srand(time(0));
        ListNode* s = head;
        int length = 0;
        while(s != nullptr)
        {
            length++;
            s = s -> next;
        }

        int x = rand() % length;

        s = head;

        while(x--)
        s = s -> next;

        return s -> val;

    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */