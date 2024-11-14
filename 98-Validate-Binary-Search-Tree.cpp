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
    bool checkLeft(TreeNode* node, int x)
    {
        if(!node) return true;

        return (node -> val < x && checkLeft(node -> left, x) && checkLeft(node -> right, x));
    }

    bool checkRight(TreeNode* node, int x)
    {
        if(!node) return true;

        return (node -> val > x && checkRight(node -> left, x) && checkRight(node -> right, x));
    }
    
    bool isValidBST(TreeNode* root) {
        if(!root) return true;

        return (checkLeft(root -> left, root -> val) && checkRight(root -> right, root -> val) && isValidBST(root -> left) && isValidBST(root -> right));
    }
};