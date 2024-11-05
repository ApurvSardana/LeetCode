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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        
        TreeNode* temp = new TreeNode(200);
        queue<TreeNode*> q;
        q.push(root);
        q.push(temp);

        int val = -1;
        vector<int> ans;

        while(!q.empty())
        {
            if(q.front() -> val == 200)
            {
            ans.push_back(val);
            q.pop();

            if(!q.empty())
            q.push(temp);
            }

            else
            {
            val = q.front() -> val;
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