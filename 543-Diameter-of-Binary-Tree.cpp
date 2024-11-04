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
    int maxDepth(TreeNode* root)
    {
        if(!root) return 0;

        int maxDepth_left = 1 + maxDepth(root -> left);
        int maxDepth_right = 1 + maxDepth(root -> right);

        return max(maxDepth_left, maxDepth_right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        int maxDepth_left = maxDepth(root -> left);
        int maxDepth_right = maxDepth(root -> right);

        return max((maxDepth_left + maxDepth_right),max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root -> right)));
    }
};