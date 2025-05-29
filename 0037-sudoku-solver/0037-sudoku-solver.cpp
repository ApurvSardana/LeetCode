class Solution {
public:
    int n; bool complete;
    bool isValid(vector<vector<char>> &board, int r, int c, char val){
        //Already Filled
        if(board[r][c] != '.') return false;

        //Row Check
        for(int col = 0; col < n; col++)
            if(board[r][col] == val) return false;
        
        //Column Check
        for(int row = 0; row < n; row++)
            if(board[row][c] == val) return false;
        
        //Sub-Grid Check
        int sr = (r/3)*3, sc = (c/3)*3;
        for(int i = sr; i <= sr+2; i++)
            for(int j = sc; j <= sc+2; j++)
                if(board[i][j] == val) return false;
        
        return true;
    }

    void solve(vector<vector<char>> &board, int row, int col){
        if(row == n){
            complete = true;
            return;
        }

        else if(col == n) solve(board, row+1, 0);

        else if(board[row][col] != '.') solve(board, row, col+1);

        else{
            for(int i = 1; i <= 9; i++){
                if(isValid(board, row, col, '0'+i)){
                    board[row][col] = '0'+i;
                    solve(board, row, col+1);

                    if(complete) return;

                    board[row][col] = '.';
                }
            }
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        n = board.size(); complete = false;

        solve(board, 0, 0);
    }
};