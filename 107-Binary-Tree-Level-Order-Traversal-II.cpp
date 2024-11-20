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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return {};

        vector<vector<int>> ans;

        vector<int> current;

        queue<TreeNode*> q;
        TreeNode* temp = new TreeNode(-1);

        q.push(root);
        q.push(temp);

        stack <vector<int>> st;

        while(!q.empty())
        {
            if(q.front() != temp)
            {
                current.push_back(q.front() -> val);

                if(q.front() -> left)
                    q.push(q.front() -> left);

                if(q.front() -> right)
                    q.push(q.front() -> right);

                q.pop();
            }

            else
            {
                st.push(current);
                current.clear();

                q.pop();

                if(!q.empty())
                    q.push(temp);
            }
        }
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};