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
    int getDecimalValue(ListNode* head) {
        vector<int> arr;

        ListNode* start = head;
        while(start){
            arr.push_back(start->val);
            start = start->next;
        }

        reverse(arr.begin(), arr.end());

        int val = 0;
        for(int i = 0; i < arr.size(); i++)
            val += arr[i]*pow(2, i);
        
        return val;
    }
};