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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> pq;
        
        if(lists.size() == 0) return nullptr;

        if(lists.size() == 1) return lists[0];

        for(int i = 0; i < lists.size(); i++)
        {
            ListNode* s = lists[i];
            while(s != nullptr)
            {
                pq.push(s -> val);
                s = s -> next;
            }
        }
        
        if(!pq.empty())
        {
        ListNode* ans = new ListNode(pq.top());
        ListNode* temp = ans;
        pq.pop();
        while(!pq.empty())
        {
            ListNode* newNode = new ListNode(pq.top());
            ans -> next = newNode;
            ans = ans -> next;
            pq.pop();
        }
        return temp;
        }

        return nullptr;
        
    }
};