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
    TreeNode* reverseOddLevels(TreeNode* root) {
        int level = 0;

        queue<TreeNode*> q;
        TreeNode* temp = new TreeNode(-1);

        q.push(root);
        q.push(temp);

        vector<TreeNode*> arr;
        
        while(!q.empty())
        {
            TreeNode* node = q.front();
            int val = node -> val;

            if(val != -1)
            {
                if(level % 2 != 0)
                    arr.push_back(node);

                if(node -> left)
                    q.push(node -> left);
                
                if(node -> right)
                    q.push(node -> right);

                q.pop();
            }

            else
            {
                int n = arr.size();

                for(int i = 0; i < n / 2; i++)
                    swap(arr[i] -> val, arr[n - i - 1] -> val);

                level++;
                arr.clear();

                q.pop();
                if(!q.empty())
                    q.push(temp);
            }
        }
        return root;
    }
};