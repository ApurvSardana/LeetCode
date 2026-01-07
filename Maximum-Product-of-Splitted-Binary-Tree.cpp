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
14    using ll = long long;
15    ll MOD = 1e9 + 7;
16    ll ans = 0;
17    ll dfs(TreeNode* root){
18        ll sum = root->val;
19        if(root->left) sum += dfs(root->left);
20        if(root->right) sum += dfs(root->right);
21        return sum;
22    }
23
24    ll dfs2(TreeNode* root, ll total_sum){
25        ll left_subtree_sum = 0LL, right_subtree_sum = 0LL;
26        if(root->left){
27            left_subtree_sum = dfs2(root->left, total_sum);
28            ans = max(ans, (total_sum-left_subtree_sum)*(left_subtree_sum));
29        }
30        if(root->right){
31            right_subtree_sum = dfs2(root->right, total_sum);
32            ans = max(ans, (total_sum-right_subtree_sum)*(right_subtree_sum));
33        }
34
35        return root->val + left_subtree_sum + right_subtree_sum;
36    }
37
38    int maxProduct(TreeNode* root) {
39        ll total_sum = dfs(root);
40        ll sum = dfs2(root, total_sum);
41        return ans%MOD;
42    }
43};