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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};

        vector<vector<int>> ans;

        queue<TreeNode*> q;

        TreeNode* temp = new TreeNode(1001);

        q.push(root);
        q.push(temp);

        vector<int> curr;

        while(!q.empty())
        {
            if(q.front() -> val != 1001)
            {
                curr.push_back(q.front() -> val);
                if(q.front() -> left != nullptr)
                q.push(q.front() -> left);

                if(q.front() -> right != nullptr)
                q.push(q.front() -> right);

                q.pop();
            }

            else
            {
                q.pop();

                ans.push_back(curr);
                curr.clear();

                if(!q.empty())
                q.push(temp);
            }
        }
    return ans;
    }
};