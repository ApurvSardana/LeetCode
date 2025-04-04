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
    vector<vector<TreeNode*>> levels;

    bool find_left(TreeNode* root, TreeNode* target){
        if(!root)
            return false;
        
        if(root -> val == target -> val)
            return true;
        
        return (find_left(root->left, target) || find_left(root->right, target));
    }

    TreeNode* lca(TreeNode* root, vector<TreeNode*> &leaves){
        int left = 0; int right = 0;
        for(auto node : leaves){
            if(node -> val == root -> val)
                return root;

            else if(find_left(root->left, node))
                left++;
            
            else
                right++;
        }

        if(left != 0 && right == 0)
            return lca(root->left, leaves);

        else if(left == 0 && right != 0)
            return lca(root->right, leaves);
        
        else
            return root;
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        queue<TreeNode*> q;
        TreeNode* dummy = new TreeNode(-1);
        q.push(root);
        q.push(dummy);

        vector<TreeNode*> temp;
        while(!q.empty()){
            TreeNode* node = q.front();
            int value = q.front()->val;
            q.pop();

            if(value >= 0){
                temp.push_back(node);
                if(node -> left)
                    q.push(node->left);
                
                if(node -> right)
                    q.push(node->right);
            }

            else{
                levels.push_back(temp);
                temp.clear();

                if(!q.empty())
                    q.push(dummy);
            }
        }

        vector<TreeNode*> leaves = levels.back();

        if(leaves.size() == 1)
            return leaves[0];

        TreeNode* ans = lca(root, leaves);
        
        return ans;
    }
};