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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};

        vector<vector<int>> ans;

        queue<TreeNode*> q;
        TreeNode* temp = new TreeNode(101);

        q.push(root);
        q.push(temp);

        vector<int> inside;

        int count = 0;

        while(!q.empty())
        {
            if(q.front() == temp)
            {
                if(count % 2 != 0)
                reverse(inside.begin(), inside.end());

                ans.push_back(inside);

                inside.clear();

                q.pop();

                if(!q.empty())
                q.push(temp);

                count++;
            }

            else
            {
                inside.push_back(q.front() -> val);

                if(q.front() -> left)
                q.push(q.front() -> left);

                if(q.front() -> right)
                q.push(q.front() -> right);

                q.pop();
            }
        }
        return ans;
    }
};