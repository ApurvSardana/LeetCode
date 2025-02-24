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
    TreeNode* constructTree(vector<int> &preorder, int prestart, int preend, vector<int> &inorder, int instart, int inend){
        if(prestart > preend || instart > inend)
            return nullptr;
        
        TreeNode* root = new TreeNode(preorder[prestart]);

        int index = find(inorder.begin() + instart, inorder.begin() + inend, root -> val) - inorder.begin();
        root -> left = constructTree(preorder, prestart+1, prestart + index - instart, inorder, instart, index-1);

        root -> right = constructTree(preorder, prestart + (index - instart) + 1, preend, inorder, index+1, inend);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int presize = preorder.size(), insize = inorder.size();
        return constructTree(preorder, 0, presize-1, inorder, 0, insize-1);
    }
};