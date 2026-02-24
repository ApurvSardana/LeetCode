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
15    int bin(string &s){
16        int n = s.length();
17        int v = 0;
18        for(int i = n-1; i >= 0; i--){
19            v += (int(s[i]-'0') * int(1<<(n-i-1)));
20        }
21        return v;
22    }
23    void dfs(TreeNode* node, string num){
24        if(!node) return;
25        if(!node->left && !node->right){
26            num += char('0'+node->val);
27            ans += bin(num);
28        }
29        dfs(node->left,num+char('0'+node->val));
30        dfs(node->right,num+char('0'+node->val));
31    }
32
33    int sumRootToLeaf(TreeNode* root) {
34        dfs(root,"");
35        return ans;
36    }
37};