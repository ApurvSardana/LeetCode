/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* f(vector<vector<int>> &grid, int r, int c, int n){
        bool one = false, zero = false;
        for(int i = r; i < r+n; i++){
            for(int j = c; j < c+n; j++){
                zero = zero || (grid[i][j] == 0);
                one = one || (grid[i][j] == 1);
            }
        }

        Node* node = new Node();
        if(one && !zero){
            node -> val = true;
            node -> isLeaf = true;
        }

        else if(!one && zero){
            node -> val = false;
            node -> isLeaf = true;
        }

        else{
            node -> isLeaf = false;
            node -> topLeft = f(grid, r, c, n/2);
            node -> topRight = f(grid, r, c+n/2, n/2);
            node -> bottomLeft = f(grid, r+n/2, c, n/2);
            node -> bottomRight = f(grid, r+n/2, c+n/2, n/2);
        }

        return node;
    }
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();

        return f(grid, 0, 0, n);
    }
};