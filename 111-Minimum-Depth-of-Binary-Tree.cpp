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
    int minDepth(TreeNode* root) {
        if(!root) return 0;

        else if(!root -> left && !root -> right)
        return 1;

        else if(!root -> left)
        return (1 + minDepth(root -> right));

        else if(!root -> right)
        return (1 + minDepth(root -> left));
        
        return min((1 + minDepth(root -> left)), (1 + minDepth(root -> right)));
    }
};