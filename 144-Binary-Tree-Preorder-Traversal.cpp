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
    void preOrder(TreeNode* &x, vector<int> &ans)
    {
        if(x == nullptr) return;
        
        ans.push_back(x -> val);
        preOrder(x -> left, ans);
        preOrder(x -> right, ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;

        if(!root) return {};

        preOrder(root, ans);

        return ans;
    }
};