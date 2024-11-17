/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long> pq;
        queue<TreeNode*> q;

        TreeNode* temp = new TreeNode(0);

        q.push(root);
        q.push(temp);

        long long sum = 0;
        while(!q.empty())
        {
            if(q.front() == temp)
            {
                pq.push(-sum);

                if(pq.size() > k)
                pq.pop();

                sum = 0;

                q.pop();

                if(!q.empty())
                q.push(temp);
            }

            else
            {
                sum += q.front() -> val;

                if(q.front() -> left)
                q.push(q.front() -> left);

                if(q.front() -> right)
                q.push(q.front() -> right);

                q.pop();
            }
        }

        if(pq.size() < k)
        return -1;

        return -pq.top();
    }
};