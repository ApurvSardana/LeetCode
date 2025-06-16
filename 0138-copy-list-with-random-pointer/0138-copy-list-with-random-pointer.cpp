/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        Node* ptr = head;
        int n = 0; 
        unordered_map<int, Node*> Onode, Nnode;
        unordered_map<Node*, int> Oindex, Nindex;

        while(ptr){
            Oindex[ptr] = n;
            Onode[n] = ptr;
            n++;
            ptr = ptr->next;
        }

        vector<bool> created(n, false); int index = 0;
        Node* newHead = nullptr;
        Node* prev = nullptr;
        ptr = head;

        while(ptr){
            //cout << Oindex[ptr] << " : " << Onode[index]->val << endl;
            Node* curr_node;
            if(!created[index]){
                curr_node = new Node(Onode[index]->val);
                created[index] = true;
                Nindex[curr_node] = index;
                Nnode[index] = curr_node;
            }

            else{
                curr_node = Nnode[index];
            }

            if(prev) prev->next = curr_node;
            else newHead = curr_node;

            if(ptr->random && created[Oindex[ptr->random]]){
                curr_node->random = Nnode[Oindex[ptr->random]];
            }
            else if(ptr->random){
                Node* random_node = new Node(ptr->random->val);
                created[Oindex[ptr->random]] = true;
                Nnode[Oindex[ptr->random]] = random_node;
                Nindex[random_node] = Oindex[ptr->random];
                curr_node->random = random_node;
            }

            index++;
            prev = curr_node;
            ptr = ptr->next;
        }

        return newHead;
    }
};