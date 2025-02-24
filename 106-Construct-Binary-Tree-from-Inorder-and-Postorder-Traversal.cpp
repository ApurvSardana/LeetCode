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
    TreeNode* constructTree(vector<int> &inorder, int instart, int inend, vector<int> &postorder, int poststart, int postend){
        if(postend < poststart || inend < instart)
            return nullptr;
        
        TreeNode* root = new TreeNode(postorder[postend]);

        int index = find(inorder.begin()+instart, inorder.end()+inend, root->val) - inorder.begin();

        root -> right = constructTree(inorder, index+1, inend, postorder, postend - (inend-index), postend-1);

        root -> left = constructTree(inorder, instart, index-1, postorder, poststart, postend - (inend-index)-1);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int insize = inorder.size(), postsize = postorder.size();
        return constructTree(inorder, 0, insize-1, postorder, 0, postsize-1);
    }
};