class Solution {
public:
    int ans;
    bool isValid(vector<string> &Board, int row, int col){
        for(int i = 0; i < col; i++)
            if(Board[row][i] == 'Q')
                return false;

        for(int i = 0; i < row; i++)
            if(Board[i][col] == 'Q')
                return false;
        
        for(int i = row-1, j = col-1; i >= 0 && j >= 0; i--,j--)
            if(Board[i][j] == 'Q')
                return false;
        
        for(int i = row-1, j = col+1; i >= 0 && col < Board.size(); i--, j++)
            if(Board[i][j] == 'Q')
                return false;
        
        return true;
    }

    void putQueens(vector<string> &Board, int row, int n){
        if(row == n){
            ans++;
            return;
        }

        for(int col = 0; col < n; col++){
            if(isValid(Board, row, col)){
                Board[row][col] = 'Q';
                putQueens(Board, row+1, n);
                Board[row][col] = '.';
            }
        }
    }

    int totalNQueens(int n) {
        ans = 0;
        vector<string> Board(n, string(n, '.'));

        putQueens(Board, 0, n);

        return ans;
    }
};