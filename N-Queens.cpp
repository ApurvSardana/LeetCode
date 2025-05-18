class Solution {
public:
    bool isValid(vector<string> &Board, int row, int col){
        //Row Check (Not Necessary)
        for(int i = 0; i < col; i++)
            if(Board[row][i] == 'Q')
                return false;
        
        //Column Check
        for(int i = 0; i < row; i++)
            if(Board[i][col] == 'Q')
                return false;
        
        //Left Diagonal Check
        for(int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--){
            if(Board[i][j] == 'Q')
                return false;
        }

        //Right Diaognal Check
        for(int i = row-1, j = col+1; i >= 0 && j < Board.size(); i--, j++){
            if(Board[i][j] == 'Q')
                return false;
        }

        return true;
    }
    void putQueens(vector<vector<string>> &answer, vector<string> &Board, int row, int n){
        //if a  solution is ready, add it to the list of solutions
        if(row == n){
            answer.push_back(Board);
            return;
        }

        //Try to place a Queen at each column in the given row
        for(int col = 0; col < n; col++){
            if(isValid(Board, row, col)){
                Board[row][col] = 'Q';
                putQueens(answer, Board, row+1, n);
                Board[row][col] = '.';
            }
        }
    }


    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> answer; //List of all solutions
        vector<string> Board(n, string(n, '.')); // Configuration of the Board

        putQueens(answer, Board, 0, n); //Try different configurations of the Board and if a solution is found, add it to answer

        return answer;
    }
};