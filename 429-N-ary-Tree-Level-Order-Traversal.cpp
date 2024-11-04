/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        
        vector<vector<int>> ans;
        queue<Node*> q;

        Node* temp = new Node(-1);

        q.push(root);
        q.push(temp);

        vector<int> curr;

        while(!q.empty())
        {
            if(q.front() -> val != -1)
            {
                curr.push_back(q.front() -> val);

                for(auto n : q.front() -> children)
                q.push(n);

                q.pop();
            }

            else
            {
                q.pop();

                ans.push_back(curr);
                curr.clear();

                if(!q.empty())
                q.push(temp);
            }
        }
        return ans;
    }
};