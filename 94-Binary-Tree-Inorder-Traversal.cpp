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
    void inOrder(TreeNode* &x, vector<int> &ans)
    {
        if(!x) return;

        inOrder(x -> left, ans);
        ans.push_back(x -> val);
        inOrder(x -> right, ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        inOrder(root, ans);

        return ans;
    }
};