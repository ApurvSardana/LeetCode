1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12class Solution {
13public:
14    int ans = 0;
15    void dfs(TreeNode* node, int val){
16        if(!node) return;
17        val <<= 1;
18        val += node->val;
19        if(!node->left && !node->right){ 
20            ans += val;
21            return;
22        }
23        dfs(node->left,val);
24        dfs(node->right,val);
25    }
26
27    int sumRootToLeaf(TreeNode* root) {
28        dfs(root,0);
29        return ans;
30    }
31};