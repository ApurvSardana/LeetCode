/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<int, int> made;
    map<int, Node*> m;
    void helper(Node* actual_node, Node* myNode)
    {
        for(auto neighbor : actual_node -> neighbors)
        {
            if(made[neighbor -> val] == 1)
            {
                myNode -> neighbors.push_back(m[neighbor -> val]);
                continue;
            }

            Node* n1 = new Node(neighbor -> val);
            made[n1 -> val] = 1;
            m[n1 -> val] = n1;
            myNode -> neighbors.push_back(n1);

            helper(neighbor, n1);
        }
    }
    Node* cloneGraph(Node* node) {
        if(node == nullptr)
            return node;

        Node* newNode = new Node(node -> val);
        made[newNode -> val] = 1;
        m[newNode -> val] = newNode;

        for(auto neighbor : node -> neighbors)
        {
            if(made[neighbor -> val] == 1)
            {
                Node* p = m[neighbor -> val];
                newNode -> neighbors.push_back(p);
                continue;
            }

            Node* n = new Node(neighbor -> val);
            made[n -> val] = 1;
            m[n -> val] = n;

            newNode -> neighbors.push_back(n);
            helper(neighbor, n);
        }
        return newNode;
    }
};