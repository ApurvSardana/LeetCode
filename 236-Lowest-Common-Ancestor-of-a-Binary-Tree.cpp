/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;

        if(root == p || root == q) return root;

        TreeNode* left_lca = lowestCommonAncestor(root -> left, p, q);
        TreeNode* right_lca = lowestCommonAncestor(root -> right, p, q);

        if(left_lca && right_lca)
        return root;

        else if(left_lca)
        return left_lca;

        else
        return right_lca;

    }
};