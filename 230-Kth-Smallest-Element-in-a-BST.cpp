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
    int count = 0;
    void inOrder(TreeNode* &node, int &k, int &ans)
    {
        if(!node) return;
        inOrder(node -> left, k, ans);
        count++;
        if(count == k)
        {
            ans = node -> val;
            return;
        }
        inOrder(node -> right, k, ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans = (int) 1e4 + 1;
        inOrder(root, k, ans); 

        return ans;
    }
};