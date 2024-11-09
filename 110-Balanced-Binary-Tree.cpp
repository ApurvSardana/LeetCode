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
    int depth(TreeNode* node)
    {
        if(!node) return 0;

        return 1 + max(depth(node -> left), depth(node -> right));

    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;

        int left = depth(root -> left);
        int right = depth(root -> right);

        if(isBalanced(root -> left) && isBalanced(root -> right) && (abs)(left - right) <= 1)
        return true;

        else
        return false;
    }
};