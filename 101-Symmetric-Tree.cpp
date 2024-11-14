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
    bool helper(TreeNode* leftTree, TreeNode* rightTree)
    {
        if(leftTree == nullptr && rightTree == nullptr)
        return true;

        else if(leftTree == nullptr)
        return false;

        else if(rightTree == nullptr)
        return false;

        return (leftTree -> val == rightTree -> val && helper(leftTree -> left, rightTree -> right) && helper(leftTree -> right, rightTree -> left));
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;

        // if(root -> left == nullptr && root -> right == nullptr)
        // return true;

        // else if(root -> left == nullptr)
        // return false;

        // else if(root -> right == nullptr)
        // return false;

        return helper(root -> left, root -> right);
    }
};